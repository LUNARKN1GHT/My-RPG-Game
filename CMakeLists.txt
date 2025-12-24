cmake_minimum_required(VERSION 3.10)
project(My-RPG-Game)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(My-RPG-Game ${SOURCES})

target_include_directories(My-RPG-Game
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
