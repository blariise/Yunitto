#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string_view>

#include "portfoliomanager.h"
#include "asset.h"

class Controller {
  public:
    Controller() = delete;
    Controller(std::unique_ptr<PortfolioManager> portfolio_manager);

    void createPortfolio(std::string_view name);
    void print() const;

  private:
    std::unique_ptr<PortfolioManager> m_portfolio_manager;
};
#endif // CONTROLLER_H

