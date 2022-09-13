cmake_minimum_required(VERSION 3.23)
project(textEditor)

set(CMAKE_CXX_STANDARD 23)
set(SFML_DIR External/include/SFML)


find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message("yeap")
endif()

include_directories(${SFML_DIR})

add_executable(textEditor main.cpp)

target_link_libraries(textEditor sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
