cmake_minimum_required(VERSION 3.16)
project(figura)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Zad2
        src/main.cpp
        src/figura.cpp)