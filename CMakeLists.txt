#this is comment

cmake_minimum_required(VERSION 3.0)

project(yaca LANGUAGES CXX)

set(myVar hoppa)
message(STATUS "value of myVar is ${myVar}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

link_directories(/usr/local/lib)

add_executable(server_executable src/yaca_server.cpp src/client.h src/client.cpp src/server.h
src/server.cpp src/user.h src/user.cpp)

target_link_libraries(server_executable boost_system pthread)


add_executable(user_executable src/user_executable.cpp src/client.h src/client.cpp src/server.h
src/server.cpp src/user.h src/user.cpp)

target_link_libraries(user_executable boost_system pthread)
