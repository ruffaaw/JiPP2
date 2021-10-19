cmake_minimum_required(VERSION 3.16)
project(SimpleCalc)
set(CMAKE_CXX_STANDARD 20)
add_executable(SimpleCalc
        src/main.cpp
        src/calc.cpp
        include/calc.h)
