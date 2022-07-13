cmake_minimum_required(VERSION 3.21)
project(Online-Shop)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)

add_executable(Online-Shop src/main.cpp
        src/finalize.cpp
        src/customer.cpp
        src/payment.cpp
        src/shoppingCart.cpp
        src/user.cpp)
