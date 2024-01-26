cmake_minimum_required(VERSION 3.25)

project(cpp-playground VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(extern)

enable_testing()
include(GoogleTest)

add_subdirectory(leetcode)
