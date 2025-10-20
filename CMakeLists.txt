cmake_minimum_required(VERSION 3.26)
project(ExpenseTracker)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Collect all source files from src/
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(ExpenseTracker ${SOURCES})
