cmake_minimum_required(VERSION 3.0.0)
project(strongly_connected)

if (MSVC)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000")
else ()
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")
endif()

#include(CTest)
#enable_testing()

add_subdirectory(src)
include_directories("./src")

add_executable(strongly_connected ./src/StronglyConnectedComponentsMain.cpp)
target_link_libraries(strongly_connected DFS BFS SCC)

add_executable(search_test ./test/search_test.cpp)
target_link_libraries(search_test DFS BFS)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
