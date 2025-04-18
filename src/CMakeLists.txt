file(
  GLOB_RECURSE CORE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/controller/*.cpp
)

add_library(yunitto_core ${CORE_SOURCES})

target_include_directories(
  yunitto_core PUBLIC
  ${CMAKE_SOURCE_DIR}/include/core
  ${CMAKE_SOURCE_DIR}/include/controller
  ${CMAKE_SOURCE_DIR}/include/gui
  ${CMAKE_SOURCE_DIR}/include/cli
)

target_link_libraries(yunitto_core PUBLIC Qt6::Core)

add_subdirectory(cli)
add_subdirectory(gui)
