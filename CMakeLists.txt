cmake_minimum_required(VERSION 3.10)

project(Josephus LANGUAGES CXX)

# Set C++ standard to C++11 for better compatibility
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(code main.cpp)

# Set compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")