#ifndef CLI_VIEW_H
#define CLI_VIEW_H

#include <optional>

#include "controller.h"

class CliView {
  public:
    CliView(Controller& controller);

    void run();

  private:
    Controller& m_controller;

    // portfolio
    void displayMainMenu() const;
    void displayPortfolioMenu();
    void displayAddPortfolioMenu();
    void displayRemovePortfolioMenu();

    void printPortfolios() const;
    std::size_t getPortfoliosNumber() const;
    void addPortfolio(std::string_view name);
    void removePortfolio(std::size_t portfolio_index);


    /// asset
    void displayAssetMenu() const;
    void addAssetMenu(std::size_t portfolio_index);
    void removeAssetMenu(std::size_t portfolio_index);
    void printAssets(std::size_t portfolio_index) const;
    
    /// transaction
    void displayTransactionMenu() const;
  
    void printTransactions(std::size_t portfolio_index, std::size_t asset_index) const;



};

void clearInputBuffer();
void clearScreen();
int getValidInputNumberInRange(int min, int max);

#endif // CLI_VIEW_H

