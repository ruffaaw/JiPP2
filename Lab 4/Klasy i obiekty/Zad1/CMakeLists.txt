cmake_minimum_required(VERSION 3.16)
project(prostopadloscian)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Zad1
        src/main.cpp
        src/prostopadloscian.cpp)