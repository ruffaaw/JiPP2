cmake_minimum_required(VERSION 3.16)
project(Node)
include_directories(include)

add_executable(Node
        src/main.cpp
        src/Node.cpp)