set(
  GUI_QRC
  ${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc
)

add_executable(
  YunittoGUI
  main.cpp
  ${CMAKE_SOURCE_DIR}/include/controller/controllerwrapper.h
  ${GUI_QRC}
)

target_link_libraries(
  YunittoGUI PRIVATE
  yunitto_core
  Qt6::Quick
  Qt6::Core
)

target_include_directories(
  YunittoGUI PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)
