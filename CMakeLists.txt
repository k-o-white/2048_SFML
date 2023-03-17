cmake_minimum_required(VERSION 3.23)
project(2048_SFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(2048_SFML main.cpp Gameplay.cpp Gameplay.h)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(2048_SFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)