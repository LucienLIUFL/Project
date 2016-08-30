cmake_minimum_required(VERSION 3.6)
project(MaplesLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp List.cpp List.h Vector.cpp Vector.h)
add_executable(MaplesLib ${SOURCE_FILES})