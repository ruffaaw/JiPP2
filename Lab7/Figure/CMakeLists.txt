cmake_minimum_required(VERSION 3.16)
project(Figure)
include_directories(include)

add_executable(Figure
        src/main.cpp
        src/figure.cpp)