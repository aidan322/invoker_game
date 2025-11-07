cmake_minimum_required(VERSION 3.16)
project(lab_oop_game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)


include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB SOURCES src/*.cpp)


add_executable(lab_oop_game ${SOURCES})


find_package(GTest QUIET)
if(GTest_FOUND)
    message(STATUS "GTest found, tests can be added manually via Makefile in /tests")
else()
    message(STATUS "GTest not found or disabled. Tests are built separately with Makefile in /tests")
endif()