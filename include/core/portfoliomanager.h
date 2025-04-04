#ifndef PORTFOLIO_MANAGER_H
#define PORTFOLIO_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>

#include "portfolio.h"

class PortfolioManager {
  public:
    PortfolioManager();

    void addPortfolio(std::unique_ptr<Portfolio> portfolio);
    void removePortfolio(std::size_t portfolio_index);
    Portfolio& getPortfolio(std::size_t portfolio_index);

    double getTotalValue() const;
    void print() const;

  private:
    std::vector<std::unique_ptr<Portfolio>> m_portfolios; 
};
#endif // PORTFOLIO_MANAGER_H

