# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/anaconda3/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /opt/anaconda3/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sean/Dynamic-RTS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sean/Dynamic-RTS/src/build

# Include any dependencies generated for this target.
include CMakeFiles/canconical_node_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/canconical_node_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/canconical_node_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/canconical_node_test.dir/flags.make

CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o: CMakeFiles/canconical_node_test.dir/flags.make
CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o: /Users/sean/Dynamic-RTS/src/tests/test_canoncial_node_set.cpp
CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o: CMakeFiles/canconical_node_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o -MF CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o.d -o CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o -c /Users/sean/Dynamic-RTS/src/tests/test_canoncial_node_set.cpp

CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/tests/test_canoncial_node_set.cpp > CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.i

CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/tests/test_canoncial_node_set.cpp -o CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.s

CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o: CMakeFiles/canconical_node_test.dir/flags.make
CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o: /Users/sean/Dynamic-RTS/src/EndpointTree.cpp
CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o: CMakeFiles/canconical_node_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o -MF CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o.d -o CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o -c /Users/sean/Dynamic-RTS/src/EndpointTree.cpp

CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/EndpointTree.cpp > CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.i

CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/EndpointTree.cpp -o CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.s

CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o: CMakeFiles/canconical_node_test.dir/flags.make
CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o: /Users/sean/Dynamic-RTS/src/TreeNode.cpp
CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o: CMakeFiles/canconical_node_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o -MF CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o.d -o CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o -c /Users/sean/Dynamic-RTS/src/TreeNode.cpp

CMakeFiles/canconical_node_test.dir/TreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/canconical_node_test.dir/TreeNode.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/TreeNode.cpp > CMakeFiles/canconical_node_test.dir/TreeNode.cpp.i

CMakeFiles/canconical_node_test.dir/TreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/canconical_node_test.dir/TreeNode.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/TreeNode.cpp -o CMakeFiles/canconical_node_test.dir/TreeNode.cpp.s

CMakeFiles/canconical_node_test.dir/Query.cpp.o: CMakeFiles/canconical_node_test.dir/flags.make
CMakeFiles/canconical_node_test.dir/Query.cpp.o: /Users/sean/Dynamic-RTS/src/Query.cpp
CMakeFiles/canconical_node_test.dir/Query.cpp.o: CMakeFiles/canconical_node_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/canconical_node_test.dir/Query.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canconical_node_test.dir/Query.cpp.o -MF CMakeFiles/canconical_node_test.dir/Query.cpp.o.d -o CMakeFiles/canconical_node_test.dir/Query.cpp.o -c /Users/sean/Dynamic-RTS/src/Query.cpp

CMakeFiles/canconical_node_test.dir/Query.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/canconical_node_test.dir/Query.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/Query.cpp > CMakeFiles/canconical_node_test.dir/Query.cpp.i

CMakeFiles/canconical_node_test.dir/Query.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/canconical_node_test.dir/Query.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/Query.cpp -o CMakeFiles/canconical_node_test.dir/Query.cpp.s

CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o: CMakeFiles/canconical_node_test.dir/flags.make
CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o: /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp
CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o: CMakeFiles/canconical_node_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o -MF CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o.d -o CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o -c /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp

CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp > CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.i

CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/DistributedTracking.cpp -o CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.s

CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o: CMakeFiles/canconical_node_test.dir/flags.make
CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o: /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp
CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o: CMakeFiles/canconical_node_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o -MF CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o.d -o CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o -c /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp

CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp > CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.i

CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sean/Dynamic-RTS/src/DTAlgorithm.cpp -o CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.s

# Object files for target canconical_node_test
canconical_node_test_OBJECTS = \
"CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o" \
"CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o" \
"CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o" \
"CMakeFiles/canconical_node_test.dir/Query.cpp.o" \
"CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o" \
"CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o"

# External object files for target canconical_node_test
canconical_node_test_EXTERNAL_OBJECTS =

canconical_node_test: CMakeFiles/canconical_node_test.dir/tests/test_canoncial_node_set.cpp.o
canconical_node_test: CMakeFiles/canconical_node_test.dir/EndpointTree.cpp.o
canconical_node_test: CMakeFiles/canconical_node_test.dir/TreeNode.cpp.o
canconical_node_test: CMakeFiles/canconical_node_test.dir/Query.cpp.o
canconical_node_test: CMakeFiles/canconical_node_test.dir/DistributedTracking.cpp.o
canconical_node_test: CMakeFiles/canconical_node_test.dir/DTAlgorithm.cpp.o
canconical_node_test: CMakeFiles/canconical_node_test.dir/build.make
canconical_node_test: lib/libgtest.a
canconical_node_test: CMakeFiles/canconical_node_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/sean/Dynamic-RTS/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable canconical_node_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/canconical_node_test.dir/link.txt --verbose=$(VERBOSE)
	/opt/anaconda3/lib/python3.8/site-packages/cmake/data/bin/cmake -D TEST_TARGET=canconical_node_test -D TEST_EXECUTABLE=/Users/sean/Dynamic-RTS/src/build/canconical_node_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/sean/Dynamic-RTS/src/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=canconical_node_test_TESTS -D CTEST_FILE=/Users/sean/Dynamic-RTS/src/build/canconical_node_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/anaconda3/lib/python3.8/site-packages/cmake/data/share/cmake-3.30/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/canconical_node_test.dir/build: canconical_node_test
.PHONY : CMakeFiles/canconical_node_test.dir/build

CMakeFiles/canconical_node_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/canconical_node_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/canconical_node_test.dir/clean

CMakeFiles/canconical_node_test.dir/depend:
	cd /Users/sean/Dynamic-RTS/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sean/Dynamic-RTS/src /Users/sean/Dynamic-RTS/src /Users/sean/Dynamic-RTS/src/build /Users/sean/Dynamic-RTS/src/build /Users/sean/Dynamic-RTS/src/build/CMakeFiles/canconical_node_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/canconical_node_test.dir/depend

