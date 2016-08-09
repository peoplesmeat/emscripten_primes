cmake_minimum_required(VERSION 3.5)
project(emscript)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp strings.cpp)
add_executable(emscript ${SOURCE_FILES})