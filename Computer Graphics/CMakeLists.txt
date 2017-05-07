cmake_minimum_required(VERSION 3.6)
project(Computer_Graphics)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Main.cpp Model/Object.cpp Model/Object.h Model/Point.cpp Model/Point.h Algorithm/Brush.cpp Algorithm/Brush.h)
set(GC_FRAMEWORK "-framework OpenGL -framework GLUT -framework Foundation")
set(COMPILER_OP "-g -Wall -Wno-deprecated")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_OP} ${GC_FRAMEWORK}")
add_executable(Computer_Graphics ${SOURCE_FILES})