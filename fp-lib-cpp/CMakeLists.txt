cmake_minimum_required(VERSION 3.26)
project(fp_lib_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)


add_executable(play_test play_test.cpp)
