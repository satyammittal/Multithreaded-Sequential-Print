cmake_minimum_required(VERSION 3.0)

project(output)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(
    output
    main.cpp
)
