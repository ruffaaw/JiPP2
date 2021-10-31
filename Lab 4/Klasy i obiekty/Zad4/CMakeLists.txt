cmake_minimum_required(VERSION 3.16)
project(student)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(Zad4
        src/main.cpp
        src/student.cpp)