cmake_minimum_required(VERSION 3.16)
project(funkcja)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Zad3
        src/main.cpp
        src/funkcja_kwadratowa.cpp)