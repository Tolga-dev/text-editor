cmake_minimum_required(VERSION 3.23)
project(textEditor)

set(CMAKE_CXX_STANDARD 23)
set(SFML_DIR External/include/SFML)


find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message("Working!")
endif()

include_directories(${SFML_DIR})

set(SOURCES
        lib/src/DocumentHandle.cpp
        lib/src/Editor.cpp
        lib/src/InputHandle.cpp
        lib/src/cursor.cpp
        main.cpp
        )

# Add an executable with the above sources
add_executable(textEditor ${SOURCES})


target_include_directories(${PROJECT_NAME} PUBLIC lib)

target_link_libraries(textEditor sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
