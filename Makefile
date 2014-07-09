# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /app/impala/impala-udf/impala-udf-samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/impala/impala-udf/impala-udf-samples

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /app/impala/impala-udf/impala-udf-samples/CMakeFiles /app/impala/impala-udf/impala-udf-samples/CMakeFiles/progress.make
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /app/impala/impala-udf/impala-udf-samples/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named uda-sample-test

# Build rule for target.
uda-sample-test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 uda-sample-test
.PHONY : uda-sample-test

# fast build rule for target.
uda-sample-test/fast:
	$(MAKE) -f CMakeFiles/uda-sample-test.dir/build.make CMakeFiles/uda-sample-test.dir/build
.PHONY : uda-sample-test/fast

#=============================================================================
# Target rules for targets named udasample

# Build rule for target.
udasample: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 udasample
.PHONY : udasample

# fast build rule for target.
udasample/fast:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/build
.PHONY : udasample/fast

#=============================================================================
# Target rules for targets named udf-sample-test

# Build rule for target.
udf-sample-test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 udf-sample-test
.PHONY : udf-sample-test

# fast build rule for target.
udf-sample-test/fast:
	$(MAKE) -f CMakeFiles/udf-sample-test.dir/build.make CMakeFiles/udf-sample-test.dir/build
.PHONY : udf-sample-test/fast

#=============================================================================
# Target rules for targets named udfsample

# Build rule for target.
udfsample: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 udfsample
.PHONY : udfsample

# fast build rule for target.
udfsample/fast:
	$(MAKE) -f CMakeFiles/udfsample.dir/build.make CMakeFiles/udfsample.dir/build
.PHONY : udfsample/fast

hyperloglog-uda.o: hyperloglog-uda.cc.o
.PHONY : hyperloglog-uda.o

# target to build an object file
hyperloglog-uda.cc.o:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/hyperloglog-uda.cc.o
.PHONY : hyperloglog-uda.cc.o

hyperloglog-uda.i: hyperloglog-uda.cc.i
.PHONY : hyperloglog-uda.i

# target to preprocess a source file
hyperloglog-uda.cc.i:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/hyperloglog-uda.cc.i
.PHONY : hyperloglog-uda.cc.i

hyperloglog-uda.s: hyperloglog-uda.cc.s
.PHONY : hyperloglog-uda.s

# target to generate assembly for a file
hyperloglog-uda.cc.s:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/hyperloglog-uda.cc.s
.PHONY : hyperloglog-uda.cc.s

uda-sample-test.o: uda-sample-test.cc.o
.PHONY : uda-sample-test.o

# target to build an object file
uda-sample-test.cc.o:
	$(MAKE) -f CMakeFiles/uda-sample-test.dir/build.make CMakeFiles/uda-sample-test.dir/uda-sample-test.cc.o
.PHONY : uda-sample-test.cc.o

uda-sample-test.i: uda-sample-test.cc.i
.PHONY : uda-sample-test.i

# target to preprocess a source file
uda-sample-test.cc.i:
	$(MAKE) -f CMakeFiles/uda-sample-test.dir/build.make CMakeFiles/uda-sample-test.dir/uda-sample-test.cc.i
.PHONY : uda-sample-test.cc.i

uda-sample-test.s: uda-sample-test.cc.s
.PHONY : uda-sample-test.s

# target to generate assembly for a file
uda-sample-test.cc.s:
	$(MAKE) -f CMakeFiles/uda-sample-test.dir/build.make CMakeFiles/uda-sample-test.dir/uda-sample-test.cc.s
.PHONY : uda-sample-test.cc.s

uda-sample.o: uda-sample.cc.o
.PHONY : uda-sample.o

# target to build an object file
uda-sample.cc.o:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/uda-sample.cc.o
.PHONY : uda-sample.cc.o

uda-sample.i: uda-sample.cc.i
.PHONY : uda-sample.i

# target to preprocess a source file
uda-sample.cc.i:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/uda-sample.cc.i
.PHONY : uda-sample.cc.i

uda-sample.s: uda-sample.cc.s
.PHONY : uda-sample.s

# target to generate assembly for a file
uda-sample.cc.s:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/uda-sample.cc.s
.PHONY : uda-sample.cc.s

udf-sample-test.o: udf-sample-test.cc.o
.PHONY : udf-sample-test.o

# target to build an object file
udf-sample-test.cc.o:
	$(MAKE) -f CMakeFiles/udf-sample-test.dir/build.make CMakeFiles/udf-sample-test.dir/udf-sample-test.cc.o
.PHONY : udf-sample-test.cc.o

udf-sample-test.i: udf-sample-test.cc.i
.PHONY : udf-sample-test.i

# target to preprocess a source file
udf-sample-test.cc.i:
	$(MAKE) -f CMakeFiles/udf-sample-test.dir/build.make CMakeFiles/udf-sample-test.dir/udf-sample-test.cc.i
.PHONY : udf-sample-test.cc.i

udf-sample-test.s: udf-sample-test.cc.s
.PHONY : udf-sample-test.s

# target to generate assembly for a file
udf-sample-test.cc.s:
	$(MAKE) -f CMakeFiles/udf-sample-test.dir/build.make CMakeFiles/udf-sample-test.dir/udf-sample-test.cc.s
.PHONY : udf-sample-test.cc.s

udf-sample.o: udf-sample.cc.o
.PHONY : udf-sample.o

# target to build an object file
udf-sample.cc.o:
	$(MAKE) -f CMakeFiles/udfsample.dir/build.make CMakeFiles/udfsample.dir/udf-sample.cc.o
.PHONY : udf-sample.cc.o

udf-sample.i: udf-sample.cc.i
.PHONY : udf-sample.i

# target to preprocess a source file
udf-sample.cc.i:
	$(MAKE) -f CMakeFiles/udfsample.dir/build.make CMakeFiles/udfsample.dir/udf-sample.cc.i
.PHONY : udf-sample.cc.i

udf-sample.s: udf-sample.cc.s
.PHONY : udf-sample.s

# target to generate assembly for a file
udf-sample.cc.s:
	$(MAKE) -f CMakeFiles/udfsample.dir/build.make CMakeFiles/udfsample.dir/udf-sample.cc.s
.PHONY : udf-sample.cc.s

variance-uda.o: variance-uda.cc.o
.PHONY : variance-uda.o

# target to build an object file
variance-uda.cc.o:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/variance-uda.cc.o
.PHONY : variance-uda.cc.o

variance-uda.i: variance-uda.cc.i
.PHONY : variance-uda.i

# target to preprocess a source file
variance-uda.cc.i:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/variance-uda.cc.i
.PHONY : variance-uda.cc.i

variance-uda.s: variance-uda.cc.s
.PHONY : variance-uda.s

# target to generate assembly for a file
variance-uda.cc.s:
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/variance-uda.cc.s
.PHONY : variance-uda.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... uda-sample-test"
	@echo "... udasample"
	@echo "... udf-sample-test"
	@echo "... udfsample"
	@echo "... hyperloglog-uda.o"
	@echo "... hyperloglog-uda.i"
	@echo "... hyperloglog-uda.s"
	@echo "... uda-sample-test.o"
	@echo "... uda-sample-test.i"
	@echo "... uda-sample-test.s"
	@echo "... uda-sample.o"
	@echo "... uda-sample.i"
	@echo "... uda-sample.s"
	@echo "... udf-sample-test.o"
	@echo "... udf-sample-test.i"
	@echo "... udf-sample-test.s"
	@echo "... udf-sample.o"
	@echo "... udf-sample.i"
	@echo "... udf-sample.s"
	@echo "... variance-uda.o"
	@echo "... variance-uda.i"
	@echo "... variance-uda.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
