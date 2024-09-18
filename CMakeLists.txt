cmake_minimum_required(VERSION 3.28)
project(Algorithm_LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.h"
        "${CMAKE_SOURCE_DIR}/src/*.cc"
)

add_executable(${PROJECT_NAME} ${SOURCES})
