# cmake_minimum_required(VERSION <specify CMake version here>)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        Circle.cpp
        Circle.h
        main.cpp
        Point.cpp
        Point.h)
