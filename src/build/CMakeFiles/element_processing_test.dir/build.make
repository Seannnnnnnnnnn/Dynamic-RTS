# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean/Dynamic-RTS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean/Dynamic-RTS/src/build

# Include any dependencies generated for this target.
include CMakeFiles/element_processing_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/element_processing_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/element_processing_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/element_processing_test.dir/flags.make

CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o: CMakeFiles/element_processing_test.dir/flags.make
CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o: ../tests/test_element_processing.cpp
CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o: CMakeFiles/element_processing_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o -MF CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o.d -o CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o -c /Users/sean/Dynamic-RTS/src/tests/test_element_processing.cpp

CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/tests/test_element_processing.cpp > CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.i

CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/tests/test_element_processing.cpp -o CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.s

CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o: CMakeFiles/element_processing_test.dir/flags.make
CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o: ../EndpointTree.cpp
CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o: CMakeFiles/element_processing_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o -MF CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o.d -o CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o -c /Users/sean/Dynamic-RTS/src/EndpointTree.cpp

CMakeFiles/element_processing_test.dir/EndpointTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element_processing_test.dir/EndpointTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/EndpointTree.cpp > CMakeFiles/element_processing_test.dir/EndpointTree.cpp.i

CMakeFiles/element_processing_test.dir/EndpointTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element_processing_test.dir/EndpointTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/EndpointTree.cpp -o CMakeFiles/element_processing_test.dir/EndpointTree.cpp.s

CMakeFiles/element_processing_test.dir/TreeNode.cpp.o: CMakeFiles/element_processing_test.dir/flags.make
CMakeFiles/element_processing_test.dir/TreeNode.cpp.o: ../TreeNode.cpp
CMakeFiles/element_processing_test.dir/TreeNode.cpp.o: CMakeFiles/element_processing_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/element_processing_test.dir/TreeNode.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element_processing_test.dir/TreeNode.cpp.o -MF CMakeFiles/element_processing_test.dir/TreeNode.cpp.o.d -o CMakeFiles/element_processing_test.dir/TreeNode.cpp.o -c /Users/sean/Dynamic-RTS/src/TreeNode.cpp

CMakeFiles/element_processing_test.dir/TreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element_processing_test.dir/TreeNode.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/TreeNode.cpp > CMakeFiles/element_processing_test.dir/TreeNode.cpp.i

CMakeFiles/element_processing_test.dir/TreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element_processing_test.dir/TreeNode.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/TreeNode.cpp -o CMakeFiles/element_processing_test.dir/TreeNode.cpp.s

CMakeFiles/element_processing_test.dir/Query.cpp.o: CMakeFiles/element_processing_test.dir/flags.make
CMakeFiles/element_processing_test.dir/Query.cpp.o: ../Query.cpp
CMakeFiles/element_processing_test.dir/Query.cpp.o: CMakeFiles/element_processing_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/element_processing_test.dir/Query.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element_processing_test.dir/Query.cpp.o -MF CMakeFiles/element_processing_test.dir/Query.cpp.o.d -o CMakeFiles/element_processing_test.dir/Query.cpp.o -c /Users/sean/Dynamic-RTS/src/Query.cpp

CMakeFiles/element_processing_test.dir/Query.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element_processing_test.dir/Query.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/Query.cpp > CMakeFiles/element_processing_test.dir/Query.cpp.i

CMakeFiles/element_processing_test.dir/Query.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element_processing_test.dir/Query.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/Query.cpp -o CMakeFiles/element_processing_test.dir/Query.cpp.s

CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o: CMakeFiles/element_processing_test.dir/flags.make
CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o: ../DistributedTracking.cpp
CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o: CMakeFiles/element_processing_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o -MF CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o.d -o CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o -c /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp

CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp > CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.i

CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp -o CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.s

CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o: CMakeFiles/element_processing_test.dir/flags.make
CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o: ../DTAlgorithm.cpp
CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o: CMakeFiles/element_processing_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o -MF CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o.d -o CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o -c /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp

CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp > CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.i

CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp -o CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.s

# Object files for target element_processing_test
element_processing_test_OBJECTS = \
"CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o" \
"CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o" \
"CMakeFiles/element_processing_test.dir/TreeNode.cpp.o" \
"CMakeFiles/element_processing_test.dir/Query.cpp.o" \
"CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o" \
"CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o"

# External object files for target element_processing_test
element_processing_test_EXTERNAL_OBJECTS =

element_processing_test: CMakeFiles/element_processing_test.dir/tests/test_element_processing.cpp.o
element_processing_test: CMakeFiles/element_processing_test.dir/EndpointTree.cpp.o
element_processing_test: CMakeFiles/element_processing_test.dir/TreeNode.cpp.o
element_processing_test: CMakeFiles/element_processing_test.dir/Query.cpp.o
element_processing_test: CMakeFiles/element_processing_test.dir/DistributedTracking.cpp.o
element_processing_test: CMakeFiles/element_processing_test.dir/DTAlgorithm.cpp.o
element_processing_test: CMakeFiles/element_processing_test.dir/build.make
element_processing_test: lib/libgtest.a
element_processing_test: CMakeFiles/element_processing_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable element_processing_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/element_processing_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/local/Cellar/cmake/3.22.3/bin/cmake -D TEST_TARGET=element_processing_test -D TEST_EXECUTABLE=/Users/sean/Dynamic-RTS/src/build/element_processing_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/sean/Dynamic-RTS/src/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=element_processing_test_TESTS -D CTEST_FILE=/Users/sean/Dynamic-RTS/src/build/element_processing_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/local/Cellar/cmake/3.22.3/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/element_processing_test.dir/build: element_processing_test
.PHONY : CMakeFiles/element_processing_test.dir/build

CMakeFiles/element_processing_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/element_processing_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/element_processing_test.dir/clean

CMakeFiles/element_processing_test.dir/depend:
	cd /Users/sean/Dynamic-RTS/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean/Dynamic-RTS/src /Users/sean/Dynamic-RTS/src /Users/sean/Dynamic-RTS/src/build /Users/sean/Dynamic-RTS/src/build /Users/sean/Dynamic-RTS/src/build/CMakeFiles/element_processing_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/element_processing_test.dir/depend

