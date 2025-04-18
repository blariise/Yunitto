#include <iostream>
#include <chrono>

#include "cliview.h"

int main() {
  
  Controller controller { std::make_unique<PortfolioManager>() };
  CliView cli { controller };

  cli.run();

  return 0;
}

