add_executable(
  YunittoCLI
  cliview.cpp
  main.cpp
)

target_link_libraries(YunittoCLI PRIVATE yunitto_core)

