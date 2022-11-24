cmake_minimum_required(VERSION 3.23)
project(Ex1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        REQUIRED)

add_executable(Ex1 main.cpp)
target_link_libraries(Ex1
        Qt::Core
        )

