cmake_minimum_required(VERSION 3.30)
project(drts)
add_executable(${PROJECT_NAME} main.cpp)

# testing
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include)

add_executable(hello_test hello_test.cc)
target_link_libraries(hello_test PRIVATE gtest)

include(GoogleTest)
gtest_discover_tests(hello_test)