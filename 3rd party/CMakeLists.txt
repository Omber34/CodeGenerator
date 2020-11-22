cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)


set(SRC
        "fmt/src/format.cc"
        "fmt/src/os.cc"
)

add_library(modules ${SRC})

target_include_directories(modules PUBLIC  "rapidjson/include")
target_include_directories(modules PUBLIC  "fmt/include")

add_subdirectory(googletest)