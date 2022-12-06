cmake_minimum_required(VERSION 3.15)
project(day1b)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(day1b main.cpp)
