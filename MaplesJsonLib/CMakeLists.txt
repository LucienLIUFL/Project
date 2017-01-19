cmake_minimum_required(VERSION 3.6)
project(MaplesJsonLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Json.cpp Json.h)
add_executable(MaplesJsonLib ${SOURCE_FILES})