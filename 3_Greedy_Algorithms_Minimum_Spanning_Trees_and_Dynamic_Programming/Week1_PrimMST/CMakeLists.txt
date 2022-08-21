cmake_minimum_required(VERSION 3.0.0)
project(prim_mst)

add_subdirectory(src)
include_directories("./src")

add_executable(${PROJECT_NAME} 
    ./src/prim_mst_main.cpp 
)
target_link_libraries(prim_mst prim_mst_algo)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
