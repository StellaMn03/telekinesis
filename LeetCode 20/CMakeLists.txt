cmake_minimum_required(VERSION 3.10)
project(Valid)

set(CMAKE_CXX_STANDARD 20)

# Add the executable
add_executable(valid main.cpp validParentheses.hpp)
