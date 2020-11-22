cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(CodeGenerator)

add_subdirectory(core/)
add_subdirectory(tests/)
add_subdirectory("3rd party/")

add_executable(CodeGenerator main.cpp)
target_link_libraries(CodeGenerator core)