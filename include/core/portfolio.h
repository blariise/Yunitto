#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <string_view>
#include <vector>
#include <memory>

#include "asset.h"

class Portfolio {
  public:
    Portfolio() = delete;
    Portfolio(std::string_view name);

    const std::string& getName() const;
    double getTotalValue() const;
    double getTotalProfit() const;
    std::size_t getAssetsNumber() const;
    const std::vector<std::unique_ptr<Asset>>& getAssets() const;

    void addAsset(std::unique_ptr<Asset> asset);
    void removeAsset(std::size_t asset_index);
    Asset& getAsset(std::size_t asset_index);
    void printAssets() const;

  private:
    std::string m_name;

    std::vector<std::unique_ptr<Asset>> m_assets;
};
#endif // PORTFOLIO_H

