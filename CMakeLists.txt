cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(n-queens-problem)

add_executable(n-queens-problem main.cpp)
add_subdirectory(src)
target_link_libraries(n-queens-problem PRIVATE n-queens-problem-lib)
