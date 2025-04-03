#include <iostream>

#include "controller.h"

int main() {
  Controller controller { std::make_unique<PortfolioManager>() };
  controller.print();
  controller.createPortfolio("crypto");
  controller.print();
  controller.createPortfolio("etf");
  controller.print();
  return 0;
}

