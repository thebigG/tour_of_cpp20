project(tests LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_compile_options(
#    -std=c++20
#    --coverage
#    -fprofile-arcs
#    -ftest-coverage
#    #Uncomment this to use modules
#    #-fmodules-ts
#)

cmake_minimum_required(VERSION 3.5)

find_package(Catch2 3 REQUIRED)
add_executable(test test.cpp)

include_directories(test ../src)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. modules)
target_link_libraries(test PRIVATE Catch2::Catch2WithMain modules gcov)
