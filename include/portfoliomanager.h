#ifndef PORTFOLIO_MANAGER_H
#define PORTFOLIO_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>

#include "portfolio.h"

class PortfolioManager {
  public:
    PortfolioManager();

    void addPortfolio(std::shared_ptr<Portfolio> portfolio);
    void removePortfolio(const std::shared_ptr<Portfolio>& portfolio);

  private:
    std::vector<std::shared_ptr<Portfolio>> m_portfolios; 
};
#endif // PORTFOLIO_MANAGER_H

