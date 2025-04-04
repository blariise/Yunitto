#include <iostream>

#include "controller.h"

int main() {
  Controller controller { std::make_unique<PortfolioManager>() };
  controller.addPortfolio("crypto");
  controller.addPortfolio("etf");
  controller.addPortfolio("3");
  controller.addPortfolio("4");


  controller.printPortfolios();
  controller.removePortfolio(1);
  
  std::cout << " \n";

  controller.printPortfolios();
  controller.addAsset(0, "brc", "x", "x", "x");
  return 0;
}

