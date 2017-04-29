cmake_minimum_required(VERSION 3.3)
project(untitled7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp fileDetails.cpp fileDetails.h main.h)
add_executable(untitled7 ${SOURCE_FILES})