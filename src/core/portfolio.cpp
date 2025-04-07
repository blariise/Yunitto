#include "portfolio.h"

Portfolio::Portfolio(std::string_view name)
  : m_name { name } {}

const std::string& Portfolio::getName() const { return m_name; }

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

void Portfolio::removeAsset(std::size_t asset_index) {
  if (asset_index < std::size(m_assets)) {
    auto asset { m_assets.begin() + asset_index };
    m_assets.erase(asset, asset + 1);
  }
}

Asset& Portfolio::getAsset(std::size_t asset_index) {
  return *m_assets.at(asset_index);
}

void Portfolio::printAssets() const {
  for (const auto& asset : m_assets)
    std::cout << asset->getName() << '\n';
}

