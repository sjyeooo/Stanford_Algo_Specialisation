cmake_minimum_required(VERSION 3.0.0)
project(median)

add_subdirectory(src)
include_directories("./src")

add_executable(median ./src/median_main.cpp)
target_link_libraries(median median_heap)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
