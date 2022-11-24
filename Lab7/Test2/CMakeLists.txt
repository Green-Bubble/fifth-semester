cmake_minimum_required(VERSION 3.23)
project(Test2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/marcinskic/Qt5.7.0/5.7/gcc_64")
find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(Test2 main.cpp)
target_link_libraries(Test2
        Qt5::Core
        )

