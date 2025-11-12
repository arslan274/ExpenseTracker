cmake_minimum_required(VERSION 3.26)
project(ExpenseTrackerGUI)

set(CMAKE_CXX_STANDARD 17)

# Find Qt (Widgets only)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
        src/main.cpp
        src/MainWindow.cpp
        src/Expense.cpp
        src/ExpenseManager.cpp
)

set(HEADERS
        include/Expense.h
        include/ExpenseManager.h
        src/MainWindow.h
)

qt_standard_project_setup()

qt_add_executable(ExpenseTracker
        ${SOURCES}
        ${HEADERS}
)

target_link_libraries(ExpenseTracker PRIVATE Qt6::Widgets)
