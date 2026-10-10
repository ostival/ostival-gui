# ==============================================================================
# Ostival - Open Silicon Technology Integration for VLSI ASIC and LOGIC
# ------------------------------------------------------------------------------
# File:        CMakeLists.txt
# Description: CMake file for builing the tool.
# License:     AGPL-3.0

# Made with 💚 by Team Ostival <hello@ostival.org>
# ==============================================================================

cmake_minimum_required(VERSION 3.16)
project(Ostival LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ostival
    src/gui/OstivalMain.cpp

    include/gui/MainGUIWindow.hpp
    src/gui/MainGUIWindow.cpp

    include/gui/StatusBarBuilder.hpp
    src/gui/StatusBarBuilder.cpp

    include/gui/CentralDockBuilder.hpp
    src/gui/CentralDockBuilder.cpp

    include/gui/LeftDockBuilder.hpp
    src/gui/LeftDockBuilder.cpp

    include/gui/RightDockBuilder.hpp
    src/gui/RightDockBuilder.cpp

    include/gui/ToolBarBuilder.hpp
    src/gui/ToolBarBuilder.cpp
)

target_include_directories(ostival PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ostival PRIVATE Qt6::Widgets)