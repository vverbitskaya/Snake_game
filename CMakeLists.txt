cmake_minimum_required(VERSION 3.16)

project (snake)
project (snake_tests)

find_package(GTest REQUIRED)

add_executable (snake main.cpp snake.cpp)
add_executable(snake_tests test.cpp snake.cpp)
target_link_libraries(snake_tests ${GTEST_LIBRARY})
include_directories(snake_tests ${GTEST_INCLUDE_DIR})