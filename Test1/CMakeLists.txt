cmake_minimum_required(VERSION 3.23)
project(Test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test1 main.cpp Pracownik.cpp Pracownik.h PracDydaktyczny.cpp PracDydaktyczny.h PracNaukowy.cpp PracNaukowy.h)
