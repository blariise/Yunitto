#include <iostream>

#include "portfoliomanager.h"
#include "portfolio.h"
#include "asset.h"
#include "transaction.h"

int main() { 
  auto pm { std::make_unique<PortfolioManager>() };
  std::cout << "HEllo first time! Create a portfolio(name): ";
  std::string portfolio_name;
  std::cin >> portfolio_name;
  //auto crypto { std::make_unique<Portfolio>(portfolio_name) };
  //pm->addPortfolio(crypto);

}

