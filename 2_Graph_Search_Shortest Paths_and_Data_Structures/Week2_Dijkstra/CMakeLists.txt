cmake_minimum_required(VERSION 3.0.0)
project(dijkstra)

#include(CTest)
#enable_testing()

add_subdirectory(src)
include_directories("./src")

add_executable(dijkstra ./src/dijkstra_main.cpp)
target_link_libraries(dijkstra dijkstra_algo)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
