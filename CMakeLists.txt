cmake_minimum_required(VERSION 3.26)
project(ExpenseTrackerGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt codegen
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Include dirs
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

# Sources (note: we explicitly list the header in src/)
set(SRC_FILES
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/MainWindow.cpp
        ${CMAKE_SOURCE_DIR}/src/Expense.cpp
        ${CMAKE_SOURCE_DIR}/src/ExpenseManager.cpp
        ${CMAKE_SOURCE_DIR}/src/MainWindow.h
        src/WelcomeWindow.h
)

qt_add_executable(ExpenseTracker
        ${SRC_FILES}
)

target_link_libraries(ExpenseTracker PRIVATE Qt6::Widgets)
