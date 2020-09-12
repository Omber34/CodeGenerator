cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(CodeGenerator)

add_subdirectory(core/)
add_executable(main main.cpp)
target_link_libraries(main core)