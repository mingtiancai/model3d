cmake_minimum_required(VERSION 3.14)

project(simpleOperation LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(simpleOperation SHARED
  simpleOperation_global.h
  simpleoperation.cpp
  simpleoperation.h
  form.h
  form.cpp
  form.ui
)

target_link_libraries(simpleOperation PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_compile_definitions(simpleOperation PRIVATE SIMPLEOPERATION_LIBRARY)
