cmake_minimum_required(VERSION 3.0.0)
project(completion_times)

include_directories("./src")

add_executable(${PROJECT_NAME} 
./src/completion_times.cpp 
./src/completion_times.h
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
