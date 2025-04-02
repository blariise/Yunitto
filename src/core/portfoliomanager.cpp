#include "portfoliomanager.h"

PortfolioManager::PortfolioManager() {}

void PortfolioManager::addPortfolio(std::shared_ptr<Portfolio> portfolio) {
  m_portfolios.push_back(portfolio);
}

void PortfolioManager::removePortfolio(const std::shared_ptr<Portfolio>& portfolio) {
  auto it { std::find(m_portfolios.begin(), m_portfolios.end(), portfolio) };
  if (it != m_portfolios.end())
    m_portfolios.erase(it);
}

double PortfolioManager::getTotalValue() const {
  double value { 0 };
  for (const auto& portfolio : m_portfolios)
    value += portfolio->getTotalValue();
  return value;
}
