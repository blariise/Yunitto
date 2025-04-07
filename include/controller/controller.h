#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string_view>

#include "portfoliomanager.h"
#include "asset.h"


using Date = std::chrono::year_month_day;

class Controller {
  public:
    Controller() = delete;
    Controller(std::unique_ptr<PortfolioManager> portfolio_manager);

    void addPortfolio(std::string_view name);
    void removePortfolio(std::size_t portfolio_index);
    void printPortfolios() const;
    std::size_t getPortfoliosNumber() const;

    void addAsset(
        std::size_t portfolio_index,
        std::string_view name,
        std::string_view ticker,
        std::string_view type,
        std::string_view currency);
    void removeAsset(std::size_t portfolio_index,std::size_t asset_index);
    void printAssets(std::size_t portfolio_index) const;

    void addTransaction(
        std::size_t portfolio_index,
        std::size_t asset_index,
        double quantity,
        double price,
        std::string_view payment_currency,
        Date date);
    void removeTransaction(
        std::size_t portfolio_index,
        std::size_t asset_index,
        std::size_t transaction_index);
    void printTransactions(
        std::size_t portfolio_index,
        std::size_t asset_index) const;

  private:
    std::unique_ptr<PortfolioManager> m_portfolio_manager;
};
#endif // CONTROLLER_H

