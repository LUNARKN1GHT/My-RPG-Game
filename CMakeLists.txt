cmake_minimum_required(VERSION 3.10)
project(My-RPG-Game)

set(CMAKE_CXX_STANDARD 17)
set(SRC DIR src)
set(INCLUDE_DIR include)

include_directories(${INCLUDE_DIR})

file(GLOB SOURCES ${SRC_DIR}/*.cpp)

add_executable(My-RPG-Game ${SOURCES})