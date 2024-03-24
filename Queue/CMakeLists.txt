cmake_minimum_required(VERSION 3.10)
project(queue)

set(CMAKE_CXX_STANDARD 20)

# Add the executable
add_executable(queue  main.cpp queue.hpp)
