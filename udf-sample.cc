// Copyright 2012 Cloudera Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "udf-sample.h"

#include <cctype>
#include <cmath>
#include <string>
#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

#define SetKey \
  BN_dec2bn(&(key->n), (const char *)n);\
  BN_dec2bn(&(key->e), (const char *)e);\
  BN_dec2bn(&(key->d), (const char *)d);\
  key->p = NULL; \
  key->q = NULL; \
  key->dmp1 = NULL; \
  key->dmq1 = NULL; \
  key->iqmp = NULL;

#define SetKey2 \
  key->n = BN_bin2bn(n, sizeof(n)-1, key->n); \
  key->e = BN_bin2bn(e, sizeof(e)-1, key->e); \
  key->d = BN_bin2bn(d, sizeof(d)-1, key->d); \
  key->p = BN_bin2bn(p, sizeof(p)-1, key->p); \
  key->q = BN_bin2bn(q, sizeof(q)-1, key->q); \
  key->dmp1 = BN_bin2bn(dmp1, sizeof(dmp1)-1, key->dmp1); \
  key->dmq1 = BN_bin2bn(dmq1, sizeof(dmq1)-1, key->dmq1); \
  key->iqmp = BN_bin2bn(iqmp, sizeof(iqmp)-1, key->iqmp);

#define RSA_KEY_SIZE          64
#define ENCKEY512_BASE64_SIZE 88
#define ENC_BLK_NUM_LIMIT     78
#define DATA_PER_ENCBLK_SIZE  53
#define MAX_DECDATA_SIZE      (DATA_PER_ENCBLK_SIZE * ENC_BLK_NUM_LIMIT)

static void key1(RSA *key);
static RSA *initializeRSAKey();

///should be secured///
static unsigned char pub_modulus[] = "7577257274191551097624277939619648834415258346195701624702241427507596352378240942764032510385901727639861216319309817735955405453593241345706416751624437";
static unsigned char pub_exp[] = "65537";
static unsigned char pri_exp[] = ""; 
//static RSA *gRSAKey = initializeRSAKey();
///////////////////////

static void key1(RSA *key) {
  // public modulus
  static unsigned char* n = pub_modulus;
  // public exponent
  static unsigned char* e = pub_exp;
  // private exponent
  static unsigned char* d = pri_exp;
  static unsigned char p[] = "";
  static unsigned char q[] = "";
  static unsigned char dmp1[] = "";
  static unsigned char dmq1[] = "";
  static unsigned char iqmp[] = "";
  static unsigned char ctext_ex[] = "";
  SetKey;
}

static RSA *initializeRSAKey() {
  static RSA *key = RSA_new();
  (void)key1(key); 
  return key;
}

int calcDecodeLength(const char* b64input, int len) { //Calculates the length of a decoded base64 string
  int padding = 0;
 
  if (b64input[len-1] == '=' && b64input[len-2] == '=') //last two chars are =
    padding = 2;
  else if (b64input[len-1] == '=') //last char is =
    padding = 1;
 
  return (int)len*0.75 - padding;
}

int Base64Encode(char *data, char* buffer, int len) {
  int writelen;
  BIO *bio, *b64;
  b64 = BIO_new(BIO_f_base64());
  FILE* stream = fmemopen(buffer, ENCKEY512_BASE64_SIZE + 1, "w");
  bio = BIO_new_fp(stream, BIO_NOCLOSE);
  BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer

  BIO_push(b64, bio);
  writelen = BIO_write(b64, data, len);
  if (writelen < 0) {
    writelen = -1;
  } else {
    (buffer)[writelen] = '\0';
  }
  BIO_flush(b64);
  BIO_free_all(b64);
  fclose(stream);

  return writelen;
}
 
int Base64Decode(char* b64message, char* buffer, int len) { //Decodes a base64 encoded string
  BIO *bio, *b64;
  int decodeLen = calcDecodeLength(b64message, len);
  FILE* stream = fmemopen(b64message, len, "r");
 
  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new_fp(stream, BIO_NOCLOSE);
  bio = BIO_push(b64, bio);
  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer
  len = BIO_read(bio, buffer, len);
  if (len != decodeLen || len < 0) {
    //test here if len == decodeLen - if not, then return an error
    len = -1;
  } else {
    (buffer)[len] = '\0';
  }
  BIO_free_all(b64);
  fclose(stream);
 
  return len; //success
}

StringVal RSAPublicEncryption(FunctionContext* context, const StringVal& input) {
  if (input.is_null || input.len == 0) return StringVal("");
  if (input.len > ENC_BLK_NUM_LIMIT * DATA_PER_ENCBLK_SIZE) {
    context->AddWarning("Encryption failed with too large data length (>4134)"); 
    return StringVal("##Encryption failed");
  }

  RSA *key = RSA_new();
  (void)key1(key); 
  RSA_blinding_off(key);

  unsigned char encdatablk[RSA_KEY_SIZE + 1];
  unsigned char encdatablk2[RSA_KEY_SIZE + 1];
  unsigned char base64str[ENCKEY512_BASE64_SIZE + 1];
  unsigned char encdata[ENCKEY512_BASE64_SIZE * ENC_BLK_NUM_LIMIT + 1];
  char *encStr = NULL, *srcStr = NULL;
  int len, enlen, base64len;
  int readBytes, totReadBytes = 0;
  int offset = 0;
  len = input.len;

  while (len > 0) {
    // 1. copy the public modulus string to a encrypted data block
    memcpy(encdatablk, pub_modulus, RSA_KEY_SIZE);
    encdatablk[RSA_KEY_SIZE] = '\0';

    if (len > DATA_PER_ENCBLK_SIZE) {
      readBytes = DATA_PER_ENCBLK_SIZE;
    } else {
      readBytes = len;
    }

    // 2. copy src data to the encrypted data block with right-aligned
    memcpy(encdatablk + (RSA_KEY_SIZE - readBytes),
           input.ptr + totReadBytes,
           readBytes);
    encdatablk[RSA_KEY_SIZE - readBytes - 1] = (unsigned char)0x0C;

    // 3. encrypt data
    // enlen should be equal to RSA_KEY_SIZE
    enlen = RSA_public_encrypt(RSA_KEY_SIZE, encdatablk, encdatablk2, key,
                               RSA_NO_PADDING);
    if (enlen != RSA_KEY_SIZE) { // error
      enlen = -1;
      break;
    } 
 
    // 4. encode the encblk to base64 array => 88 bytes blk
    base64len = Base64Encode((char *)encdatablk2, (char *)base64str, enlen);
    if (base64len != ENCKEY512_BASE64_SIZE && base64len != RSA_KEY_SIZE) { // error
      base64len = -1;
      break;
    } else {
      if (base64len == RSA_KEY_SIZE)
        base64len = ENCKEY512_BASE64_SIZE;
    }

    // 5. append the base64 array to encdata
    memcpy(encdata + offset, base64str, base64len);
    offset += base64len;
    totReadBytes += readBytes;
    len -= readBytes;
  }

  //CRYPTO_cleanup_all_ex_data();
  ERR_remove_thread_state(NULL);

  //printf("debug: offset=%d, dtext=%s\n", offset, dtext);

  if (enlen == RSA_KEY_SIZE && base64len == ENCKEY512_BASE64_SIZE) {
    if (offset == 0)
      return StringVal("");
    // impala bug
    //StringVal result(context, offset);
    //memcpy(result.ptr, encdata, offset);
    uint8_t* buffer =
      reinterpret_cast<uint8_t*>(context->GetFunctionState(FunctionContext::THREAD_LOCAL));
    memcpy(buffer, encdata, offset);
    StringVal result(buffer, offset);
    return result;
  } else {
    // on format error
    char errmsg[1024];
    int  cpylen = input.len, errmsglen;
    strcpy(errmsg, "Encryption failed with invalid data format: ");
    errmsglen = strlen(errmsg);
    if (errmsglen + input.len >= 1024)
      cpylen = 1024 - errmsglen - 1;
    memcpy(errmsg + errmsglen, input.ptr, cpylen);
    errmsg[errmsglen + cpylen] = '\0';
    context->AddWarning((char *)errmsg); 
    return StringVal("##decryption failed");
  }
}


StringVal RSAPrivateDecryption(FunctionContext* context, const StringVal& input) {
  if (input.is_null || input.len == 0) return StringVal("");
  if (input.len > ENC_BLK_NUM_LIMIT * ENCKEY512_BASE64_SIZE) {
    context->AddWarning("Decryption failed with too large encrypted data length (>6864)"); 
    return StringVal("##decryption failed");
  }

  RSA *key = RSA_new();
  (void)key1(key); 
  RSA_blinding_off(key);

  unsigned char mtext[256];
  unsigned char dtext[MAX_DECDATA_SIZE + 1] = {0};
  unsigned char base64str[ENCKEY512_BASE64_SIZE + 1];
  unsigned char encstr[256];
  int len, plen, enclen;
  int readBytes, totReadBytes = 0;
  int start, offset = 0;
  len = input.len;

  if (input.len % ENCKEY512_BASE64_SIZE != 0)
    goto _DECRYPT_FORMAT_ERR; 

  while (len > 0) {
    if (len >= ENCKEY512_BASE64_SIZE) {
      readBytes = ENCKEY512_BASE64_SIZE;
      memcpy(base64str, input.ptr + totReadBytes, readBytes);
      base64str[readBytes] = '\0';
    } else { // error
      goto _DECRYPT_FORMAT_ERR;
    }
    totReadBytes += readBytes;

    enclen = Base64Decode((char *)base64str, (char *)encstr, ENCKEY512_BASE64_SIZE);
    if (enclen != RSA_KEY_SIZE)
      goto _DECRYPT_FORMAT_ERR; 
    // plen should be equal to RSA_KEY_SIZE
    plen = RSA_private_decrypt(enclen, encstr, mtext, key,
                               RSA_NO_PADDING);
    if (plen != RSA_KEY_SIZE) {
      plen = -1;
      break;
    }
    start = plen; 
    for (int i = plen - 1; i >= 0; i--) {
      if (mtext[i] == (unsigned char)0x0C) {
        start = i + 1;
        break;
      }
    } 

    memcpy(dtext + offset, mtext + start, plen - start);
    offset += (plen - start);
    len -= readBytes;
  }

  //CRYPTO_cleanup_all_ex_data();
  ERR_remove_thread_state(NULL);

  //printf("debug: offset=%d, dtext=%s\n", offset, dtext);

  if (plen == RSA_KEY_SIZE && enclen == RSA_KEY_SIZE) {
    if (offset == 0)
      return StringVal("");
    uint8_t* buffer =
      reinterpret_cast<uint8_t*>(context->GetFunctionState(FunctionContext::THREAD_LOCAL));
    memcpy(buffer, dtext, offset);
    StringVal result(buffer, offset);
    //impala bug
    //StringVal result(context, offset);
    //memcpy(result.ptr, dtext, offset);
    return result;
  } else {
_DECRYPT_FORMAT_ERR:
    // on format error
    char errmsg[1024];
    int  cpylen = input.len, errmsglen;
    strcpy(errmsg, "Decryption failed with unknown data format: ");
    errmsglen = strlen(errmsg);
    if (errmsglen + input.len >= 1024)
      cpylen = 1024 - errmsglen - 1;
    memcpy(errmsg + errmsglen, input.ptr, cpylen);
    errmsg[errmsglen + cpylen] = '\0';
    context->AddWarning((char *)errmsg); 
    return StringVal("##decryption failed");
  }
}

void CryptoPrepare(FunctionContext* context, FunctionContext::FunctionStateScope scope) {
  if (scope == FunctionContext::THREAD_LOCAL) {
    // Allocate shared state to store 'arg' or a null IntVal
    uint8_t* state = context->Allocate(ENC_BLK_NUM_LIMIT * ENCKEY512_BASE64_SIZE);
    memset(state, 0x00, ENC_BLK_NUM_LIMIT * ENCKEY512_BASE64_SIZE);
    // Set the shared state in the function context
    context->SetFunctionState(scope, (void*)state);
  }
}

void CryptoClose(FunctionContext* context, FunctionContext::FunctionStateScope scope) {
  if (scope == FunctionContext::THREAD_LOCAL) {
    context->Free(reinterpret_cast<uint8_t*>(context->GetFunctionState(scope)));
    context->SetFunctionState(scope, NULL);
  }
}

// In this sample we are declaring a UDF that adds two ints and returns an int.
IntVal AddUdf(FunctionContext* context, const IntVal& arg1, const IntVal& arg2) {
  if (arg1.is_null || arg2.is_null) return IntVal::null();
  return IntVal(arg1.val + arg2.val);
}

// Multiple UDFs can be defined in the same file

BooleanVal FuzzyEquals(FunctionContext* ctx, const DoubleVal& x, const DoubleVal& y) {
  const double EPSILON = 0.000001f;
  if (x.is_null || y.is_null) return BooleanVal::null();
  double delta = fabs(x.val - y.val);
  return BooleanVal(delta < EPSILON);
}

// Check if the input string has any occurrences of the letters (a,e,i,o,u).
// Case-insensitive, so also detects (A,E,I,O,U).
BooleanVal HasVowels(FunctionContext* context, const StringVal& input) {
  if (input.is_null) return BooleanVal::null();

  int index;
  uint8_t *ptr;

  for (ptr = input.ptr, index = 0; index < input.len; index++, ptr++) {
    uint8_t c = tolower(*ptr);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      return BooleanVal(true);
    }
  }
  return BooleanVal(false);
}

// Count all occurrences of the letters (a,e,i,o,u) in the input string.
// Case-insensitive, so also counts (A,E,I,O,U).
IntVal CountVowels(FunctionContext* context, const StringVal& arg1) {
  if (arg1.is_null) return IntVal::null();

  int count;
  int index;
  uint8_t *ptr;

  for (ptr = arg1.ptr, count = 0, index = 0; index < arg1.len; index++, ptr++) {
    uint8_t c = tolower(*ptr);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
    }
  }
  return IntVal(count);
}

// Remove all occurrences of the letters (a,e,i,o,u) from the input string.
// Case-insensitive, so also removes (A,E,I,O,U).
StringVal StripVowels(FunctionContext* context, const StringVal& arg1) {
  if (arg1.is_null) return StringVal::null();

  int index;
  std::string original((const char *)arg1.ptr,arg1.len);
  std::string shorter("");

  for (index = 0; index < original.length(); index++) {
    uint8_t c = original[index];
    uint8_t l = tolower(c);

    if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') {
      continue;
    }
    else {
        shorter.append(1, (char)c);
    }
  }
  // The modified string is stored in 'shorter', which is destroyed when this function
  // ends. We need to make a string val and copy the contents.
  // NB: Only the version of the ctor that takes a context object allocates new memory.
  StringVal result(context, shorter.size());
  memcpy(result.ptr, shorter.c_str(), shorter.size());
  return result;
}

// In the prepare function, allocate an IntVal and set it as the shared state. This
// IntVal will be set to the result to be returned, i.e. the argument if it's constant
// and null otherwise.
void ReturnConstantArgPrepare(
    FunctionContext* context, FunctionContext::FunctionStateScope scope) {
  // UDFs should check the version to avoid unimplemented functions from being called
  if (context->version() < FunctionContext::v1_3) {
    context->SetError("This UDF can only be used with Impala 1.3 or higher");
    return;
  }
  // TODO: this can be FRAGMENT_LOCAL once it's implemented since we're creating
  // read-only state
  if (scope == FunctionContext::THREAD_LOCAL) {
    // Get the constant value of the 'const_val' argument in ReturnConstantArg(). If this
    // value is not constant, 'arg' will be NULL.
    IntVal* arg = reinterpret_cast<IntVal*>(context->GetConstantArg(0));
    // Allocate shared state to store 'arg' or a null IntVal
    IntVal* state = reinterpret_cast<IntVal*>(context->Allocate(sizeof(IntVal)));
    *state = (arg != NULL) ? *arg : IntVal::null();
    // Set the shared state in the function context
    context->SetFunctionState(scope, state);
  }
}

// Retreives and returns the shared state set in the prepare function
IntVal ReturnConstantArg(FunctionContext* context, const IntVal& const_val) {
  IntVal* state = reinterpret_cast<IntVal*>(
      context->GetFunctionState(FunctionContext::THREAD_LOCAL));
  return *state;
}

// Cleans up the shared state
void ReturnConstantArgClose(
    FunctionContext* context, FunctionContext::FunctionStateScope scope) {
  if (scope == FunctionContext::THREAD_LOCAL) {
    // Retreive and deallocate the shared state
    void* state = context->GetFunctionState(scope);
    context->Free(reinterpret_cast<uint8_t*>(state));
    context->SetFunctionState(scope, NULL);
  }
}

