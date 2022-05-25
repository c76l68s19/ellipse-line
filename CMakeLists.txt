cmake_minimum_required(VERSION 3.22)
project(ellipse_line)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ellipse_line
        Ellipse.cpp
        Ellipse.h
        LineSegment.h
        main.cpp
        Point.h)
