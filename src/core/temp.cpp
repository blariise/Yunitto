#include <iostream>
#include <chrono>

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
  controller.addAsset(0, "eth", "x", "x", "x");
  //controller.removeAsset(0, 1);
  controller.printAssets(0);


  const std::chrono::time_point now{std::chrono::system_clock::now()};
  const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};
  controller.addTransaction(0, 1, 10, 30, "PLN", ymd);
  controller.removeTransaction(0,1,0);
  controller.printTransactions(0,1);

  return 0;
}

