# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

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

# Include any dependencies generated for this target.
include CMakeFiles/udasample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udasample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udasample.dir/flags.make

CMakeFiles/udasample.dir/uda-sample.cc.o: CMakeFiles/udasample.dir/flags.make
CMakeFiles/udasample.dir/uda-sample.cc.o: uda-sample.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /app/impala/impala-udf/impala-udf-samples/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/udasample.dir/uda-sample.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/udasample.dir/uda-sample.cc.o -c /app/impala/impala-udf/impala-udf-samples/uda-sample.cc

CMakeFiles/udasample.dir/uda-sample.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udasample.dir/uda-sample.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /app/impala/impala-udf/impala-udf-samples/uda-sample.cc > CMakeFiles/udasample.dir/uda-sample.cc.i

CMakeFiles/udasample.dir/uda-sample.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udasample.dir/uda-sample.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /app/impala/impala-udf/impala-udf-samples/uda-sample.cc -o CMakeFiles/udasample.dir/uda-sample.cc.s

CMakeFiles/udasample.dir/uda-sample.cc.o.requires:
.PHONY : CMakeFiles/udasample.dir/uda-sample.cc.o.requires

CMakeFiles/udasample.dir/uda-sample.cc.o.provides: CMakeFiles/udasample.dir/uda-sample.cc.o.requires
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/uda-sample.cc.o.provides.build
.PHONY : CMakeFiles/udasample.dir/uda-sample.cc.o.provides

CMakeFiles/udasample.dir/uda-sample.cc.o.provides.build: CMakeFiles/udasample.dir/uda-sample.cc.o
.PHONY : CMakeFiles/udasample.dir/uda-sample.cc.o.provides.build

CMakeFiles/udasample.dir/hyperloglog-uda.cc.o: CMakeFiles/udasample.dir/flags.make
CMakeFiles/udasample.dir/hyperloglog-uda.cc.o: hyperloglog-uda.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /app/impala/impala-udf/impala-udf-samples/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/udasample.dir/hyperloglog-uda.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/udasample.dir/hyperloglog-uda.cc.o -c /app/impala/impala-udf/impala-udf-samples/hyperloglog-uda.cc

CMakeFiles/udasample.dir/hyperloglog-uda.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udasample.dir/hyperloglog-uda.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /app/impala/impala-udf/impala-udf-samples/hyperloglog-uda.cc > CMakeFiles/udasample.dir/hyperloglog-uda.cc.i

CMakeFiles/udasample.dir/hyperloglog-uda.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udasample.dir/hyperloglog-uda.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /app/impala/impala-udf/impala-udf-samples/hyperloglog-uda.cc -o CMakeFiles/udasample.dir/hyperloglog-uda.cc.s

CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.requires:
.PHONY : CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.requires

CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.provides: CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.requires
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.provides.build
.PHONY : CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.provides

CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.provides.build: CMakeFiles/udasample.dir/hyperloglog-uda.cc.o
.PHONY : CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.provides.build

CMakeFiles/udasample.dir/variance-uda.cc.o: CMakeFiles/udasample.dir/flags.make
CMakeFiles/udasample.dir/variance-uda.cc.o: variance-uda.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /app/impala/impala-udf/impala-udf-samples/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/udasample.dir/variance-uda.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/udasample.dir/variance-uda.cc.o -c /app/impala/impala-udf/impala-udf-samples/variance-uda.cc

CMakeFiles/udasample.dir/variance-uda.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udasample.dir/variance-uda.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /app/impala/impala-udf/impala-udf-samples/variance-uda.cc > CMakeFiles/udasample.dir/variance-uda.cc.i

CMakeFiles/udasample.dir/variance-uda.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udasample.dir/variance-uda.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /app/impala/impala-udf/impala-udf-samples/variance-uda.cc -o CMakeFiles/udasample.dir/variance-uda.cc.s

CMakeFiles/udasample.dir/variance-uda.cc.o.requires:
.PHONY : CMakeFiles/udasample.dir/variance-uda.cc.o.requires

CMakeFiles/udasample.dir/variance-uda.cc.o.provides: CMakeFiles/udasample.dir/variance-uda.cc.o.requires
	$(MAKE) -f CMakeFiles/udasample.dir/build.make CMakeFiles/udasample.dir/variance-uda.cc.o.provides.build
.PHONY : CMakeFiles/udasample.dir/variance-uda.cc.o.provides

CMakeFiles/udasample.dir/variance-uda.cc.o.provides.build: CMakeFiles/udasample.dir/variance-uda.cc.o
.PHONY : CMakeFiles/udasample.dir/variance-uda.cc.o.provides.build

# Object files for target udasample
udasample_OBJECTS = \
"CMakeFiles/udasample.dir/uda-sample.cc.o" \
"CMakeFiles/udasample.dir/hyperloglog-uda.cc.o" \
"CMakeFiles/udasample.dir/variance-uda.cc.o"

# External object files for target udasample
udasample_EXTERNAL_OBJECTS =

build/libudasample.so: CMakeFiles/udasample.dir/uda-sample.cc.o
build/libudasample.so: CMakeFiles/udasample.dir/hyperloglog-uda.cc.o
build/libudasample.so: CMakeFiles/udasample.dir/variance-uda.cc.o
build/libudasample.so: CMakeFiles/udasample.dir/build.make
build/libudasample.so: CMakeFiles/udasample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library build/libudasample.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udasample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udasample.dir/build: build/libudasample.so
.PHONY : CMakeFiles/udasample.dir/build

CMakeFiles/udasample.dir/requires: CMakeFiles/udasample.dir/uda-sample.cc.o.requires
CMakeFiles/udasample.dir/requires: CMakeFiles/udasample.dir/hyperloglog-uda.cc.o.requires
CMakeFiles/udasample.dir/requires: CMakeFiles/udasample.dir/variance-uda.cc.o.requires
.PHONY : CMakeFiles/udasample.dir/requires

CMakeFiles/udasample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udasample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udasample.dir/clean

CMakeFiles/udasample.dir/depend:
	cd /app/impala/impala-udf/impala-udf-samples && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/impala/impala-udf/impala-udf-samples /app/impala/impala-udf/impala-udf-samples /app/impala/impala-udf/impala-udf-samples /app/impala/impala-udf/impala-udf-samples /app/impala/impala-udf/impala-udf-samples/CMakeFiles/udasample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udasample.dir/depend

