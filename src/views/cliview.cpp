#include <iostream>

#include "cliview.h"

CliView::CliView(Controller& controller) :
  m_controller { controller } {}

void CliView::run() {
  while(true) {
    displayMainMenu();
    std::cout << "Enter option: ";
    char choice{};
    std::cin >> choice;

    if (choice == '+') {
      clearScreen();
      displayAddPortfolioMenu();
      std::string portfolio_name {};
      std::cin >> portfolio_name;
      m_controller.addPortfolio(portfolio_name);
    }
      // addportfolioMenu()
    continue;
    break;
  }
}

void CliView::displayMainMenu() const {
  std::cout << "===Portfolios===\n";
  printPortfolios();
  std::cout << "Add portfolio (+)\n";
  auto portfoliosNumber { getPortfoliosNumber() };
  if (portfoliosNumber != 0) {
    std::cout << "Remove portfolio (-)\n";
    std::cout << "Select portfolio (0";
    if (portfoliosNumber == 1)
      std::cout << ")\n";
    else
      std::cout << " - " << portfoliosNumber - 1 << ")\n";
  }
}

void CliView::displayAddPortfolioMenu() const {
  std::cout << "===Add portfolio===\n";
  std::cout << "Enter name of porfolio You want to add: "; 
}


void CliView::printPortfolios() const {
  m_controller.printPortfolios();
}

std::size_t CliView::getPortfoliosNumber() const {
  return m_controller.getPortfoliosNumber();
}

void CliView::addPortfolio(std::string_view name) {
  m_controller.addPortfolio(name);
}

void CliView::removePortfolio(std::size_t portfolio_index) {
  m_controller.removePortfolio(portfolio_index);
}

void CliView::clearScreen() const {
  std::cout << "\033[2J\033[1;1H";
}
