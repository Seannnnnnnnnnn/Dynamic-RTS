cmake_minimum_required(VERSION 3.30)

project(drts)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main 
            main.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}")

# testing
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include)

add_executable(endpoint_tree_test 
            tests/test_endpoint_tree.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h)

add_executable(canconical_node_test 
            tests/test_canoncial_node_set.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h)

target_link_libraries(endpoint_tree_test PRIVATE gtest)
target_link_libraries(canconical_node_test PRIVATE gtest)

include(GoogleTest)
gtest_discover_tests(endpoint_tree_test)
gtest_discover_tests(canconical_node_test)