cmake_minimum_required(VERSION 3.0.0)
project(two_sum)

add_subdirectory(src)
include_directories("./src")

add_executable(two_sum ./src/two_sum_main.cpp)
target_link_libraries(two_sum two_sum_algo)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
