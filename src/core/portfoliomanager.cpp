#include "portfoliomanager.h"

PortfolioManager::PortfolioManager() {}

void PortfolioManager::addPortfolio(std::unique_ptr<Portfolio> portfolio) {
  m_portfolios.emplace_back(std::move(portfolio));
}

double PortfolioManager::getTotalValue() const {
  double value { 0 };
  for (const auto& portfolio : m_portfolios)
    value += portfolio->getTotalValue();
  return value;
}
