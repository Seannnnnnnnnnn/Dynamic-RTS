cmake_minimum_required(VERSION 3.20)

project(drts)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# Add compiler warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif(MSVC)
    add_compile_options(/W4 /WX)
endif()

add_executable(main 
            main.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h
            DistributedTracking.cpp
            DTAlgorithm.cpp)

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
            StreamElement.h
            DistributedTracking.cpp
            DTAlgorithm.cpp)

add_executable(canconical_node_test 
            tests/test_canoncial_node_set.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h
            DistributedTracking.cpp
            DTAlgorithm.cpp)

add_executable(element_processing_test 
            tests/test_element_processing.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h
            DistributedTracking.cpp
            DTAlgorithm.cpp)

add_executable(distributed_tracking_test 
            tests/test_distributed_tracking.cpp
            TreeNode.cpp
            Query.cpp
            DistributedTracking.cpp)

add_executable(DT_algorithm_test 
            tests/test_DT_algorithm.cpp
            tests/DTAlgorithmTest.cpp
            EndpointTree.cpp
            TreeNode.cpp
            Query.cpp
            StreamElement.h
            DistributedTracking.cpp
            DTAlgorithm.cpp)

target_link_libraries(endpoint_tree_test PRIVATE gtest)
target_link_libraries(canconical_node_test PRIVATE gtest)
target_link_libraries(element_processing_test PRIVATE gtest)
target_link_libraries(distributed_tracking_test PRIVATE gtest)
target_link_libraries(DT_algorithm_test PRIVATE gtest)

include(GoogleTest)
gtest_discover_tests(endpoint_tree_test)
gtest_discover_tests(canconical_node_test)
gtest_discover_tests(element_processing_test)
gtest_discover_tests(distributed_tracking_test)
gtest_discover_tests(DT_algorithm_test)
