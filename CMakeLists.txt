# Copyright 2012 Cloudera Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 2.6)

# where to put generated libraries
set(LIBRARY_OUTPUT_PATH "build")
# where to put generated binaries
set(EXECUTABLE_OUTPUT_PATH "build")

set(INCLUDE_PATH "include")
#set(LIB_PATH "lib")

find_program(CLANG_EXECUTABLE clang++)

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -Llib")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L lib")

# Function to generate rule to cross compile a source file to an IR module.
# This should be called with the .cc src file and it will generate a
# src-file-ir target that can be built.
# e.g. COMPILE_TO_IR(test.cc) generates the "test-ir" make target.
set(IR_COMPILE_FLAGS "-emit-llvm" "-Iinclude" "-O3" "-c")
function(COMPILE_TO_IR SRC_FILE)
  get_filename_component(BASE_NAME ${SRC_FILE} NAME_WE)
  set(OUTPUT_FILE "build/${BASE_NAME}.ll")
  add_custom_command(
    OUTPUT ${OUTPUT_FILE}
    COMMAND ${CLANG_EXECUTABLE} ${IR_COMPILE_FLAGS} ${SRC_FILE} -o ${OUTPUT_FILE}
    DEPENDS ${SRC_FILE})
  add_custom_target(${BASE_NAME}-ir ALL DEPENDS ${OUTPUT_FILE})
endfunction(COMPILE_TO_IR)

#set(HEADER_FILES udf)

include_directories(${INCLUDE_PATH})
#link_directories(${LIB_PATH})

# Build the UDA/UDFs into a shared library.
add_library(udfsample SHARED udf-sample.cc)
target_link_libraries(udfsample crypto ssl)
add_library(udasample SHARED uda-sample.cc hyperloglog-uda.cc variance-uda.cc)

# Custom targest to cross compile UDA/UDF to ir
if (CLANG_EXECUTABLE)
  COMPILE_TO_IR(udf-sample.cc )
  COMPILE_TO_IR(uda-sample.cc )
endif(CLANG_EXECUTABLE)

# This is an example of how to use the test harness to help develop UDF and UDAs.
#include_directories("include")
add_executable(udf-sample-test udf-sample-test.cc)
target_link_libraries(udf-sample-test ImpalaUdf udfsample crypto ssl dl)
add_executable(uda-sample-test uda-sample-test.cc)
target_link_libraries(uda-sample-test ImpalaUdf udasample)

