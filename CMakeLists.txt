cmake_minimum_required(VERSION 3.15)

project(porfolio-tracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_executable(porfolio-tracker ${SOURCES})

target_link_libraries(porfolio-tracker PRIVATE Qt6::Widgets)
