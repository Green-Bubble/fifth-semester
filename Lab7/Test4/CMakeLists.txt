cmake_minimum_required(VERSION 3.23)
project(Test4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/marcinskic/Qt5.7.0/5.7/gcc_64")
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Test4 main.cpp cokolwiek.cpp cokolwiek.h cokolwiek.ui)
target_link_libraries(Test4
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

