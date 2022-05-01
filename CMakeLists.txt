cmake_minimum_required(VERSION 3.5)

project(tour_of_cpp20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(
    -std=c++20
    --coverage
    -fno-inline
    -fno-inline-small-functions
    -fno-default-inline
    -fkeep-inline-functions
    -fno-exceptions
    #Uncomment this to use modules
    #-fmodules-ts
)

set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS    "-lgcov")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )
#Uncomment this to use modules
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
#string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
#  "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> <SOURCE>"
#  " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
#  " ${flags_to_scan_deps} -fdep-file=<DYNDEP_FILE> -fdep-output=<OBJECT>"
#  )


set(MODULE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter6.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter5.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter5_impl.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter4_impl.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter3_impl.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter2_impl.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/chapter2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

#I know this is weird, but it'd make the transition back to modules a lot
#easier.
add_library(modules ${MODULE_SOURCES})
add_executable(tour_of_cpp20 ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(tour_of_cpp20 modules gcov)
#add_subdirectory(tests)

