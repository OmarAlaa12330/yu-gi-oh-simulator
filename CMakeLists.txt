cmake_minimum_required(VERSION 3.28)
project(yu-gi-oh-simulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 src/main.cpp
        include/Card.hpp
        include/PlayerField.hpp)
