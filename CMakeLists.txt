#this is comment

cmake_minimum_required(VERSION 3.0)

project(yaca LANGUAGES CXX)

set(myVar hoppa)
message(STATUS "value of myVar is ${myVar}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(osman src/main.cpp)
