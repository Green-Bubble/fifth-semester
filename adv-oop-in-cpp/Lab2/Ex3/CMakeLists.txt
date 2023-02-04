cmake_minimum_required(VERSION 3.23)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex3 main.cpp Buffer.cpp Buffer.h MeanBuffer.cpp MeanBuffer.h MaxBuffer.cpp MaxBuffer.h)
