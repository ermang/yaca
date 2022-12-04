#this is comment

cmake_minimum_required(VERSION 3.0)

project(yaca LANGUAGES CXX)

set(myVar hoppa)
message(STATUS "value of myVar is ${myVar}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(CMAKE_CXX_FLAGS "-g -Wall")

link_directories(/usr/local/lib)

add_executable(yaca_server_executable src/yaca_server_executable.cpp src/client.h src/client.cpp src/yaca_server.h
src/yaca_server.cpp src/user.h src/user.cpp src/server_connection.h src/server_connection.cpp)

target_link_libraries(yaca_server_executable boost_system pthread)


add_executable(yaca_client_executable src/yaca_client_executable.cpp src/client.h src/client.cpp src/yaca_server.h
src/yaca_server.cpp src/user.h src/user.cpp src/yaca_client.h src/yaca_client.cpp src/connection.h src/connection.cpp src/yaca_client.h src/yaca_client.cpp  src/server_connection.h src/server_connection.cpp)

target_link_libraries(yaca_client_executable boost_system pthread)
