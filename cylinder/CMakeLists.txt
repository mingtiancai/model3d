cmake_minimum_required(VERSION 3.14)

project(cylinder LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(cylinder SHARED
  cylinder_global.h
  cylinder.cpp
  cylinder.h
)

target_link_libraries(cylinder PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${VTK_LIBRARIES})

target_compile_definitions(cylinder PRIVATE CYLINDER_LIBRARY)
