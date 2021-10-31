cmake_minimum_required(VERSION 3.16)
project(destruktor)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Destruktor
        src/main.cpp
        src/destruktor.cpp)