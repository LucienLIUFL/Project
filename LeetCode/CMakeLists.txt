cmake_minimum_required(VERSION 3.6)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MaplesTool/Maples.cpp MaplesTool/Maples.h MaplesTool/Test.cpp MaplesTool/Test.h)
add_executable(LeetCode ${SOURCE_FILES})