cmake_minimum_required(VERSION 3.5)

project(tour_of_cpp20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -std=c++20
    -fmodules-ts
)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
  "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> <SOURCE>"
  " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
  " ${flags_to_scan_deps} -fdep-file=<DYNDEP_FILE> -fdep-output=<OBJECT>"
  )


set(MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter2.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter2_impl.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter3.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter3_impl.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_library(modules ${MODULE_SOURCES})
add_executable(tour_of_cpp20 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(tour_of_cpp20 modules)

