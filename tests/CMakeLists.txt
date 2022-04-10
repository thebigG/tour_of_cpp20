project(tests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.5)

find_package(Catch2 3 REQUIRED)

add_executable(test test.cpp)


include_directories(test ../src)

target_link_libraries(test PRIVATE Catch2::Catch2WithMain modules)
