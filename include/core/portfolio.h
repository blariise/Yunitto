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
    int getPortfolioId() const;
    void addAsset(std::unique_ptr<Asset> asset);

  private:
    std::string m_name;

    static inline int s_id_generator { 0 };
    int m_portfolio_id;

    std::vector<std::unique_ptr<Asset>> m_assets;
};
#endif // PORTFOLIO_H

