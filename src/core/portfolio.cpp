#include "portfolio.h"

Portfolio::Portfolio(std::string_view name)
  : m_name { name }
  , m_portfolio_id { s_id_generator++ } {}

const std::string& Portfolio::getName() const { return m_name; }
int Portfolio::getPortfolioId() const { return m_portfolio_id; }

double Portfolio::getTotalValue() const {
  double value { 0 };
  for (const auto& asset : m_assets)
    value += asset->getCurrentValue();
  return value;
}

double Portfolio::getTotalProfit() const {
  double profit { 0 };
  for (const auto& asset : m_assets)
    profit += asset->getProfit();
  return profit;
}

void Portfolio::addAsset(std::unique_ptr<Asset> asset) {
  m_assets.emplace_back(std::move(asset));
}
