#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string_view>

#include "portfoliomanager.h"
#include "asset.h"

class Controller {
  public:
    Controller() = delete;
    Controller(std::unique_ptr<PortfolioManager> portfolio_manager);

    void addPortfolio(std::string_view name);
    void removePortfolio(std::size_t portfolio_index);
    void printPortfolios() const;

    void addAsset(
        std::size_t portfolio_index,
        std::string_view name,
        std::string_view ticker,
        std::string_view type,
        std::string_view currency);
    void removeAsset(std::size_t portfolio_index,std::size_t asset_index);
    void printAssets(std::size_t portfolio_index) const;

  private:
    std::unique_ptr<PortfolioManager> m_portfolio_manager;
};
#endif // CONTROLLER_H

