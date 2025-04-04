#include <iostream>
#include <memory>

#include "controller.h"

Controller::Controller(std::unique_ptr<PortfolioManager> portfolio_manager)
  : m_portfolio_manager { std::move(portfolio_manager) } {}

void Controller::addPortfolio(std::string_view name) {
  m_portfolio_manager->addPortfolio(std::make_unique<Portfolio>(name));
}

void Controller::removePortfolio(std::size_t portfolio_index) {
  m_portfolio_manager->removePortfolio(portfolio_index);
}

void Controller::printPortfolios() const {
  m_portfolio_manager->print();
}

void Controller::addAsset(
    std::size_t portfolio_index,
    std::string_view name,
    std::string_view ticker,
    std::string_view type,
    std::string_view currency) {
  Portfolio& portfolio { m_portfolio_manager->getPortfolio(portfolio_index) };
  portfolio.addAsset(std::make_unique<Asset>(name, ticker, type, currency));
}

