#include <iostream>

#include "portfoliomanager.h"

PortfolioManager::PortfolioManager() {}

void PortfolioManager::addPortfolio(std::unique_ptr<Portfolio> portfolio) {
  m_portfolios.emplace_back(std::move(portfolio));
}

void PortfolioManager::removePortfolio(std::size_t portfolio_index) {
  if (portfolio_index < std::size(m_portfolios)) {
    auto portfolio { m_portfolios.begin() + portfolio_index };
    m_portfolios.erase(portfolio, portfolio + 1);
  }
}

std::size_t PortfolioManager::getPortfoliosNumber() const {
  return std::size(m_portfolios);
}

const std::vector<std::unique_ptr<Portfolio>>& PortfolioManager::getPortfolios() const {
  return m_portfolios;
}

double PortfolioManager::getTotalValue() const {
  double value { 0 };
  for (const auto& portfolio : m_portfolios)
    value += portfolio->getValue();
  return value;
}

double PortfolioManager::getPortfolioValue(std::size_t portfolio_index) const {
  return m_portfolios.at(portfolio_index)->getValue();
}

void PortfolioManager::print() const {
  int i { 0 };
  for (const auto& portfolio : m_portfolios)
    std::cout << ++i << ". " << portfolio->getName() << '\n'; 
}

Portfolio& PortfolioManager::getPortfolio(std::size_t portfolio_index) const {
  return *m_portfolios.at(portfolio_index);
}

const std::string& PortfolioManager::getPortfolioName(std::size_t portfolio_index) const {
  return m_portfolios.at(portfolio_index)->getName();
}

std::size_t PortfolioManager::getAssetsNumber(std::size_t portfolio_index) const {
  return m_portfolios.at(portfolio_index)->getAssetsNumber();
}

std::size_t PortfolioManager::getTransactionsNumber(
    std::size_t portfolio_index,
    std::size_t asset_index) const {
  return getAsset(portfolio_index, asset_index).getTransactionsNumber();
}

Asset& PortfolioManager::getAsset(std::size_t portfolio_index, std::size_t asset_index) const {
  return getPortfolio(portfolio_index).getAsset(asset_index);
}

const std::vector<std::unique_ptr<Asset>>& PortfolioManager::getAssets(std::size_t portfolio_index) const {
  return getPortfolio(portfolio_index).getAssets();
}

const std::vector<std::unique_ptr<Transaction>>& PortfolioManager::getTransactions(
    std::size_t portfolio_index,
    std::size_t asset_index) const {
  return getAsset(portfolio_index, asset_index).getTransactions();
}

const Transaction& PortfolioManager::getTransaction(
    std::size_t portfolio_index,
    std::size_t asset_index,
    std::size_t transaction_index) const {
  return getAsset(portfolio_index, asset_index).getTransaction(transaction_index);
}
