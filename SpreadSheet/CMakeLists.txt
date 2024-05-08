cmake_minimum_required(VERSION 3.10)
project(spreadSheet)

set(CMAKE_CXX_STANDARD 20)

# Add the executable
add_executable(spreadSheet cell.hpp spreadSheet.hpp main.cpp)
