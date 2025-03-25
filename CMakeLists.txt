cmake_minimum_required(VERSION 3.15)

project(porfolio-tracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SOURCES "src/*.cpp")

add_executable(porfolio-tracker ${SOURCES})

target_include_directories(portfolio-tracker PRIVATE include)
