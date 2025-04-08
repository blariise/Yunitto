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

void CliView::displayMainMenu() {
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
  // - 1, because portfolios are displayed from 1
  displayAssetMenu(portfolio_index - 1);
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

  // - 1, because portfolios are displayed from 1
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

void CliView::displayAssetMenu(std::size_t portfolio_index) {
  while (true) {
    clearScreen();
    std::string portfolio_name { m_controller.getPortfolioName(portfolio_index) };
    std::cout << "=== Portfolio: " << portfolio_name << " #" << portfolio_index << " ===\n";
    // print portfolio value;
    std::cout << "\nOptions\n";
    std::cout << "1.Manage assets\n";
    std::cout << "2.Add asset\n";
    std::cout << "3.Remove asset\n";
    std::cout << "4.Back to portfolios\n";

    int choice { getValidInputNumberInRange(1, 4) };
    clearScreen();
    switch (choice) {
      case 1:
        displayAssetManageMenu(portfolio_index);
        break;
      case 2:
        displayAddAssetMenu(portfolio_index);
        break;
      case 3:
        displayRemoveAssetMenu(portfolio_index);
        break;
      case 4:
        return;
      default:
        std::cout << "Invalid option. Try again.\n";
        break;
    }
  }
}

void CliView::displayAssetManageMenu(std::size_t portfolio_index) {
  std::cout << "=== Select asset ===\n";

  // getAssetsNumber()
  if (getAssetsNumber(portfolio_index) == 0) {
    std::cout << "No assets\n";
    std::cout << "Press enter to continue: ";
    std::string escape;
    std::getline(std::cin, escape);
    return;
  }

  printAssets(portfolio_index);
  std::cout << "\nEnter an asset You want to manage\n";
  
  std::string temp;
  std::cin >> temp;
  // - 1, because portfolios are displayed from 1
  
}

void CliView::displayAddAssetMenu(std::size_t portfolio_index) {
  std::cout << "===Add asset===\n";
  std::cout << "Enter name of asset to add or empty enter to exit: ";

  std::string asset_name;
  std::getline(std::cin, asset_name);
  if (asset_name.empty())
    return;

  std::string asset_ticker;
  std::string asset_type;
  std::string asset_currency;
  
  std::cout << "Enter ticker: ";
  std::cin >> asset_ticker;

  std::cout << "Enter type: ";
  std::cin >> asset_type;

  std::cout << "Enter currency: ";
  std::cin >> asset_currency;

  addAsset(portfolio_index, asset_name, asset_ticker, asset_type, asset_currency);
}

void CliView::displayRemoveAssetMenu(std::size_t portfolio_index) {
  std::cout << "===Remove assets===\n";
  
  printAssets(portfolio_index);

  // no portfolio
  if (getAssetsNumber(portfolio_index) == 0) {
    std::cout << "No assets to remove\n";
    std::string temp;
    std::getline(std::cin, temp);
    return;
  }

  int asset_index { 
    getValidInputNumberInRange(1, static_cast<int>(getAssetsNumber(portfolio_index))) };
  std::cout << asset_index;

  // - 1, because portfolios are displayed from 1
  removeAsset(portfolio_index, asset_index - 1);
}

std::size_t CliView::getAssetsNumber(std::size_t portfolio_index) const {
  return m_controller.getAssetsNumber(portfolio_index);
}

void CliView::addAsset(
    std::size_t portfolio_index,
    std::string_view name,
    std::string_view ticker,
    std::string_view type,
    std::string_view currency) {
  m_controller.addAsset(portfolio_index, name, ticker, type, currency);
}

void CliView::removeAsset(std::size_t portfolio_index, std::size_t asset_index) {
  m_controller.removeAsset(portfolio_index, asset_index);
}

void CliView::printAssets(std::size_t portfolio_index) const {
  m_controller.printAssets(portfolio_index);
}

/// helpers

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

