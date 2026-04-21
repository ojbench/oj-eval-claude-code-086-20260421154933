cmake_minimum_required(VERSION 3.10)
project(problem_086_swap_tree_nodes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output the executable to the project root as required by the OJ
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(code main.cpp)

target_compile_options(code PRIVATE -O2 -Wall -Wextra -Wpedantic)
