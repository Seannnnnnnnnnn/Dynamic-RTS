# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\seanl\Dynamic-RTS\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\seanl\Dynamic-RTS\src\build

# Include any dependencies generated for this target.
include CMakeFiles/DT_algorithm_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DT_algorithm_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DT_algorithm_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DT_algorithm_test.dir/flags.make

CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/tests/test_DT_algorithm.cpp
CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\tests\test_DT_algorithm.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\tests\test_DT_algorithm.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\tests\test_DT_algorithm.cpp

CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\tests\test_DT_algorithm.cpp > CMakeFiles\DT_algorithm_test.dir\tests\test_DT_algorithm.cpp.i

CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\tests\test_DT_algorithm.cpp -o CMakeFiles\DT_algorithm_test.dir\tests\test_DT_algorithm.cpp.s

CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/tests/DTAlgorithmTest.cpp
CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\tests\DTAlgorithmTest.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\tests\DTAlgorithmTest.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\tests\DTAlgorithmTest.cpp

CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\tests\DTAlgorithmTest.cpp > CMakeFiles\DT_algorithm_test.dir\tests\DTAlgorithmTest.cpp.i

CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\tests\DTAlgorithmTest.cpp -o CMakeFiles\DT_algorithm_test.dir\tests\DTAlgorithmTest.cpp.s

CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/EndpointTree.cpp
CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\EndpointTree.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\EndpointTree.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\EndpointTree.cpp

CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\EndpointTree.cpp > CMakeFiles\DT_algorithm_test.dir\EndpointTree.cpp.i

CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\EndpointTree.cpp -o CMakeFiles\DT_algorithm_test.dir\EndpointTree.cpp.s

CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/TreeNode.cpp
CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\TreeNode.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\TreeNode.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\TreeNode.cpp

CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\TreeNode.cpp > CMakeFiles\DT_algorithm_test.dir\TreeNode.cpp.i

CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\TreeNode.cpp -o CMakeFiles\DT_algorithm_test.dir\TreeNode.cpp.s

CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/Query.cpp
CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\Query.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\Query.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\Query.cpp

CMakeFiles/DT_algorithm_test.dir/Query.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/Query.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\Query.cpp > CMakeFiles\DT_algorithm_test.dir\Query.cpp.i

CMakeFiles/DT_algorithm_test.dir/Query.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/Query.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\Query.cpp -o CMakeFiles\DT_algorithm_test.dir\Query.cpp.s

CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/DistributedTracking.cpp
CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\DistributedTracking.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\DistributedTracking.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\DistributedTracking.cpp

CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\DistributedTracking.cpp > CMakeFiles\DT_algorithm_test.dir\DistributedTracking.cpp.i

CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\DistributedTracking.cpp -o CMakeFiles\DT_algorithm_test.dir\DistributedTracking.cpp.s

CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj: CMakeFiles/DT_algorithm_test.dir/flags.make
CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj: CMakeFiles/DT_algorithm_test.dir/includes_CXX.rsp
CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj: C:/Users/seanl/Dynamic-RTS/src/DTAlgorithm.cpp
CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj: CMakeFiles/DT_algorithm_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj -MF CMakeFiles\DT_algorithm_test.dir\DTAlgorithm.cpp.obj.d -o CMakeFiles\DT_algorithm_test.dir\DTAlgorithm.cpp.obj -c C:\Users\seanl\Dynamic-RTS\src\DTAlgorithm.cpp

CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.i"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\seanl\Dynamic-RTS\src\DTAlgorithm.cpp > CMakeFiles\DT_algorithm_test.dir\DTAlgorithm.cpp.i

CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.s"
	C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\seanl\Dynamic-RTS\src\DTAlgorithm.cpp -o CMakeFiles\DT_algorithm_test.dir\DTAlgorithm.cpp.s

# Object files for target DT_algorithm_test
DT_algorithm_test_OBJECTS = \
"CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj" \
"CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj" \
"CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj" \
"CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj" \
"CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj" \
"CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj" \
"CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj"

# External object files for target DT_algorithm_test
DT_algorithm_test_EXTERNAL_OBJECTS =

DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/tests/test_DT_algorithm.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/tests/DTAlgorithmTest.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/EndpointTree.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/TreeNode.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/Query.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/DistributedTracking.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/DTAlgorithm.cpp.obj
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/build.make
DT_algorithm_test.exe: lib/libgtest.a
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/linkLibs.rsp
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/objects1.rsp
DT_algorithm_test.exe: CMakeFiles/DT_algorithm_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable DT_algorithm_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DT_algorithm_test.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\CMake\bin\cmake.exe" -D TEST_TARGET=DT_algorithm_test -D TEST_EXECUTABLE=C:/Users/seanl/Dynamic-RTS/src/build/DT_algorithm_test.exe -D TEST_EXECUTOR= -D TEST_WORKING_DIR=C:/Users/seanl/Dynamic-RTS/src/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=DT_algorithm_test_TESTS -D CTEST_FILE=C:/Users/seanl/Dynamic-RTS/src/build/DT_algorithm_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P "C:/Program Files/CMake/share/cmake-3.30/Modules/GoogleTestAddTests.cmake"

# Rule to build all files generated by this target.
CMakeFiles/DT_algorithm_test.dir/build: DT_algorithm_test.exe
.PHONY : CMakeFiles/DT_algorithm_test.dir/build

CMakeFiles/DT_algorithm_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DT_algorithm_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DT_algorithm_test.dir/clean

CMakeFiles/DT_algorithm_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\seanl\Dynamic-RTS\src C:\Users\seanl\Dynamic-RTS\src C:\Users\seanl\Dynamic-RTS\src\build C:\Users\seanl\Dynamic-RTS\src\build C:\Users\seanl\Dynamic-RTS\src\build\CMakeFiles\DT_algorithm_test.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DT_algorithm_test.dir/depend

