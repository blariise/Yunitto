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
    double getTotalValue();
    double getTotalProfit();

    void addAsset(std::shared_ptr<Asset> asset);

  private:
    std::string m_name;

    std::vector<std::shared_ptr<Asset>> m_assets;
};
#endif // PORTFOLIO_H

