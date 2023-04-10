cmake_minimum_required(VERSION 3.23)
project(textEditor)

set(CMAKE_CXX_STANDARD 23)
set(SFML_DIR External/include/SFML)

add_subdirectory(WindowsView)
include_directories(${SFML_DIR})

add_executable(textEditor main.cpp)

target_link_libraries(textEditor window)

