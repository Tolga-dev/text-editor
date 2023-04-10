set(SFML_DIR ../External/include/SFML)

include_directories(${SFML_DIR})


find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    message("yeap")
endif()

add_library(window window.cpp)

target_link_libraries(window sfml-audio sfml-network sfml-graphics sfml-window sfml-system)
