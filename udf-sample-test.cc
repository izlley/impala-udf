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

#include <iostream>
#include <stdio.h>

#include <udf/udf-test-harness.h>
#include "udf-sample.h"

using namespace impala;
using namespace impala_udf;
using namespace std;

int main(int argc, char** argv) {
  bool passed = true;
  uint8_t* state;
  uint8_t** state_ptr = &state;
  printf("state=%d, state_ptr=%d\n",(long)state, (long)state_ptr);
  *state = 1;
  printf("*state=%d, **state_ptr=%d\n",*state, **state_ptr);
  printf("state=%d, state_ptr=%d\n",(long)state, (long)state_ptr);
/*
  // Using the test harness helpers, validate the UDF returns correct results.
  // These tests validate:
  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPublicEncryption,
      StringVal("352740060671976"),
      StringVal("IcQlTvWDdSDwqZfJeTBR28Juczz2HKQLl1EPUO1o3GXc01quv4msJA6dfV5Wh51o15IMCZth+zr9LuvaOZhBWA=="));
  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPublicEncryption,
      StringVal("shop_29543289"),
      StringVal("YF+0uKM2oW/ltryXWDE0wPOws1dF2iDhl5KLU5grLBRvWFoii+bEpCd2JtKRNzopzwOB10XVMw60odOCY6IMLw=="));
  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPublicEncryption,
      StringVal("alskcmdjfndhcndjfksuejdncjdkfjsncjdkfjshencjdksjdnfjcnskdjfncjskdfjcnsjdfdf"),
      StringVal("G494uuJkCmsfMPeWrg4So24Sq4otXVATnmJfk6JE/WpA1iT6+7MlanPw1hlHs0DCY6BBPlu1DdBFxm4WH65c2A==TW47L2YaDruLgUr9jZ1GzrdCQtDK8UTZPnaOqq1GDuGhYXYZXcc/PufWoo9MK7WxRCGYlIKnwvYcabtJb09CxA=="));
  // Using the test harness helpers, validate the UDF returns correct results.
  // These tests validate:
  //  RSAPrivateDecryption(null) == null
  //  RSAPrivateDecryption("") == ""
  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPrivateDecryption,
      StringVal::null(),
      StringVal(""));

  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPrivateDecryption,
      StringVal(""),
      StringVal(""));

  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPrivateDecryption,
      StringVal("1234"),
      StringVal("##decryption failed"));

  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPrivateDecryption,
      StringVal("IcQlTvWDdSDwqZfJeTBR28Juczz2HKQLl1EPUO1o3GXc01quv4msJA6dfV5Wh51o15IMCZth+zr9LuvaOZhBWA=="),
      StringVal("352740060671976"));

  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPrivateDecryption,
      StringVal("IcQlTvWDdSDwqZfJeTBR28Juczz2HKQLl1EPUO1o3GXc01quv4msJA6dfV5Wh51o15IMCZth+zr9LuvaOZhBWA==YF+0uKM2oW/ltryXWDE0wPOws1dF2iDhl5KLU5grLBRvWFoii+bEpCd2JtKRNzopzwOB10XVMw60odOCY6IMLw==IcQlTvWDdSDwqZfJeTBR28Juczz2HKQLl1EPUO1o3GXc01quv4msJA6dfV5Wh51o15IMCZth+zr9LuvaOZhBWA=="),
      StringVal("352740060671976shop_29543289352740060671976"));

  passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
      RSAPrivateDecryption,
      StringVal("NMkPYG6fv0tgI0yBNkwvq65CZyK4pADex5BHN4EVnZEEFxGueuP+90ZgY+kXhc2J9HWlAlV/h7ekHB/Xz0CfJA=="),
      StringVal("shop_15124945"));
*/
  // Using the test harness helpers, validate the UDF returns correct results.
  // These tests validate:
  //  AddUdf(1, 2) == 3
  //  AddUdf(null, 2) == null
  passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
      AddUdf, IntVal(1), IntVal(2), IntVal(3));
  passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
      AddUdf, IntVal::null(), IntVal(2), IntVal::null());

  // Test FuzzyEquals sample.
  passed &= UdfTestHarness::ValidateUdf<BooleanVal, DoubleVal, DoubleVal>(
      FuzzyEquals, DoubleVal(1.0), DoubleVal(1.0000000001), BooleanVal(true));
  passed &= UdfTestHarness::ValidateUdf<BooleanVal, DoubleVal, DoubleVal>(
      FuzzyEquals, DoubleVal(1.1), DoubleVal(1.0), BooleanVal(false));

  // Test ReturnConstantArg sample
  // Test constant arg
  vector<AnyVal*> constant_args;
  constant_args.push_back(new IntVal(1));
  passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal>(
      ReturnConstantArg, IntVal(1), IntVal(1), ReturnConstantArgPrepare,
      ReturnConstantArgClose, constant_args);
  delete constant_args[0];
  constant_args.clear();

  // Test non-constant arg
  passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal>(
      ReturnConstantArg, IntVal(1), IntVal::null(), ReturnConstantArgPrepare,
      ReturnConstantArgClose);

  cout << "Tests " << (passed ? "Passed." : "Failed.") << endl;
  return !passed;
}
