#ifndef PORTFOLIO_MANAGER_H
#define PORTFOLIO_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>

#include "portfolio.h"

class PortfolioManager {
  public:
    PortfolioManager();

    void addPortfolio(std::unique_ptr<Portfolio> portfolio);
    void removePortfolio(std::size_t portfolio_index);
    Portfolio& getPortfolio(std::size_t portfolio_index) const;
    const std::vector<std::unique_ptr<Portfolio>>& getPortfolios() const;
    double getPortfolioValue(std::size_t portfolio_index) const;

    std::size_t getPortfoliosNumber() const;
    double getTotalValue() const;
    void print() const;
    const std::string& getPortfolioName(std::size_t portfolio_index) const;

    std::size_t getAssetsNumber(std::size_t portfolio_index) const;
    std::size_t getTransactionsNumber(
        std::size_t portfolio_index,
        std::size_t asset_index) const;
  
    Asset& getAsset(std::size_t portfolio_index, std::size_t asset_index) const;
    const std::vector<std::unique_ptr<Asset>>& getAssets(
        std::size_t portfolio_index) const;

    const std::vector<std::unique_ptr<Transaction>>& getTransactions(
        std::size_t portfolio_index,
        std::size_t asset_index) const;

    const Transaction& getTransaction(
        std::size_t portfolio_index,
        std::size_t asset_index,
        std::size_t transaction_index) const;

  private:
    std::vector<std::unique_ptr<Portfolio>> m_portfolios; 
};
#endif // PORTFOLIO_MANAGER_H

