#include <iostream>
#include <limits>

#include "cliview.h"

CliView::CliView(Controller& controller) :
  m_controller { controller } {}

void CliView::run() {
  while(true) {
    clearScreen();
    displayMainMenu();

    int choice { getValidInputNumberInRange(1, 4) };

    clearScreen();
    switch (choice) {
      case 1:
        displayPortfolioMenu();
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
        std::cout << "Invalid option. Try again.\n";
        break;
    }
  }
}

/// Portfolio

void CliView::displayMainMenu() const {
  std::cout << "==PortfolioManager==\n";
  std::cout << "\nOptions\n";
  std::cout << "1.Manage portfolios\n";
  std::cout << "2.Add portfolio\n";
  std::cout << "3.Remove portfolio\n";
  std::cout << "4.Exit\n";
}

void CliView::displayPortfolioMenu() {
  std::cout << "===Select portfolio===\n";

  if (getPortfoliosNumber() == 0) {
    std::cout << "No portfolios\n";
    std::cout << "Press enter to continue: ";
    std::string escape;
    std::getline(std::cin, escape);
    return;
  }

  printPortfolios();

  std::cout << "\nEnter a portfolio You want to manage\n";
  int portfolio_index {
    getValidInputNumberInRange(1, static_cast<int>(getPortfoliosNumber())) };
}

void CliView::displayAddPortfolioMenu() {
  std::cout << "===Add portfolio===\n";
  std::cout << "Enter name of porfolio to add or empty enter to exit: ";
  std::string portfolio_name;
  std::getline(std::cin, portfolio_name);
  if (portfolio_name.empty())
    return;
  m_controller.addPortfolio(portfolio_name);
}

void CliView::displayRemovePortfolioMenu() {
  std::cout << "===Remove portfolio===\n";
  
  printPortfolios();

  // no portfolio
  if (getPortfoliosNumber() == 0) {
    std::cout << "No portfolio to remove\n";
    std::string temp;
    std::getline(std::cin, temp);
    return;
  }

  int portfolio_index { 
    getValidInputNumberInRange(1, static_cast<int>(getPortfoliosNumber())) };
  std::cout << portfolio_index; 

  removePortfolio(portfolio_index - 1);
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

/// Asset




void clearInputBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void clearScreen() {
  std::cout << "\033[2J\033[1;1H"; // idk googled it
}

int getValidInputNumberInRange(int min, int max) {
  int choice;
  while (true) {
    std::cout << "Enter number: ";
    if (std::cin >> choice && choice >= min && choice <= max) {
      clearInputBuffer();
      return choice;
    } else {
      std::cout << "Invalid input.\n";
      clearInputBuffer();
    }
  }
}
