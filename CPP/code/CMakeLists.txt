cmake_minimum_required(VERSION 3.10)

project(cpp_code)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(exp_std_thread std_thread.cpp)
target_link_libraries(exp_std_thread)
