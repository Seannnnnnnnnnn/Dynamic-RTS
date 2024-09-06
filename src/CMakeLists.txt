cmake_minimum_required(VERSION 3.30)

project(drts)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main 
            main.cpp
            EndpointTree.cpp
            Query.cpp)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}")

# Specify that we are building a console application (not a GUI application)
if (WIN32)
    target_link_libraries(main PRIVATE -mconsole)
endif()

# testing
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include)

add_executable(endpoint_tree_test 
            tests/test_endpoint_tree.cpp
            EndpointTree.cpp
            Query.cpp)

target_link_libraries(endpoint_tree_test PRIVATE gtest)

include(GoogleTest)
gtest_discover_tests(endpoint_tree_test)