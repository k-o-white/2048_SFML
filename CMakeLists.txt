cmake_minimum_required(VERSION 3.23)
project(2048_SFML)

include(FetchContent)

set(SFML_VERSION 2.5.1)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(2048_SFML WIN32 main.cpp Gameplay.cpp Gameplay.h MainMenu.cpp MainMenu.h)

target_link_libraries(2048_SFML sfml-system sfml-window sfml-graphics)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
