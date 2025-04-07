#include <iostream>

#include "cliview.h"

CliView::CliView(Controller& controller) :
  m_controller { controller } {}

void CliView::run() {
  while(true) {
    clearScreen();
    displayMainMenu();
    
    int choice;
    std::cout << "Enter option: ";
    while (!(std::cin >> choice)) {
      choice = -1;
      clearInputBuffer();
      break;
    }

    switch (choice) {
      case 1:
        clearScreen();
        printPortfolios();
        int temp;
        std::cin >> temp;
        break;
      case 2:
        displayAddPortfolioMenu();
        break;
      case 3:
        displayRemovePortfolioMenu();
        break;
      case 4:
        return;
      default:
        std::cout << "Wrong input\n";
        break;
    }
  
  }
}

void CliView::displayMainMenu() const {
  std::cout << "==PortfolioManager==\n";
  std::cout << "\nOptions\n";
  std::cout << "1.Manage portfolios\n";
  std::cout << "2.Add portfolio\n";
  std::cout << "3.Remove portfolio\n";
  std::cout << "4.Exit\n";
}

void CliView::displayAddPortfolioMenu() const {
  clearInputBuffer();
  clearScreen();
  std::cout << "===Add portfolio===\n";
  std::cout << "Enter name of porfolio You want to add: ";
  std::string portfolio_name;
  std::getline(std::cin, portfolio_name);
  m_controller.addPortfolio(portfolio_name);
}

void CliView::displayRemovePortfolioMenu() const {
  clearScreen();
  std::cout << "===Remove portfolio===\n";
  printPortfolios();
  std::cout << "Enter number of portfolio You want to remove: ";
  std::size_t portfolio_index;
  
  while (!(std::cin >> portfolio_index) ||
          portfolio_index > getPortfoliosNumber() - 1) {
    std::cout << "Enter a valid number!: ";
  }
  removePortfolio(portfolio_index);
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

void CliView::removePortfolio(std::size_t portfolio_index) const {
  m_controller.removePortfolio(portfolio_index);
}

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

void clearInputBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

