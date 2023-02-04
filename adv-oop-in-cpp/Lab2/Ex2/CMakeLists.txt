cmake_minimum_required(VERSION 3.23)
project(Ex2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex2 main.cpp Employee.cpp Employee.h Developer.cpp Developer.h TeamLeader.cpp TeamLeader.h)
