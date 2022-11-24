cmake_minimum_required(VERSION 3.23)
project(Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(Test main.cpp)
target_link_libraries(Test
        Qt5::Core
        )

