cmake_minimum_required(VERSION 3.15)

project(porfolio-tracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 with Quick
find_package(Qt6 REQUIRED COMPONENTS Quick)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Collect all QML and other resource files (e.g., images) in the resources directory
file(GLOB_RECURSE RESOURCE_FILES "resources/*")

# Include directories for headers
include_directories(include)

# Create the executable
add_executable(porfolio-tracker ${SOURCES})

# Link Qt Quick library
target_link_libraries(porfolio-tracker PRIVATE Qt6::Quick)

# Add generated resource files to the project
target_sources(porfolio-tracker PRIVATE ${QML_RESOURCE})

