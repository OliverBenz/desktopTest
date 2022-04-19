cmake_minimum_required(VERSION 3.16)
project(Desktop VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_compile_options(-Wall -Wextra -pedantic)

# Packages
find_package(Qt6 REQUIRED COMPONENTS Gui)

# Executable
add_executable(Desktop main.cpp MainWindow.hpp MainWindow.cpp)

# Linking
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Qt6::Gui)
