#include <iostream>
#include <memory>

#include "controller.h"

Controller::Controller(std::unique_ptr<PortfolioManager> portfolio_manager)
  : m_portfolio_manager { std::move(portfolio_manager) } {}

void Controller::createPortfolio(std::string_view name) {
  m_portfolio_manager->addPortfolio(std::make_unique<Portfolio>(name));
}

void Controller::print() const {
  m_portfolio_manager->print();
}
