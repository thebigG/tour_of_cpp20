cmake_minimum_required(VERSION 3.5)

project(tour_of_cpp20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter3.cpp)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter3.h)


add_executable(tour_of_cpp20 ${SOURCES} ${HEADERS})

set(CMAKE_CXX_FLAGS "-fmodules-ts")
