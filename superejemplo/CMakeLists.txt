cmake_minimum_required(VERSION 3.20)
project(lista)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES main.cpp student.cpp node.cpp)

add_executable(lista ${SOURCES})