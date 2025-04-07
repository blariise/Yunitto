#include <iostream>
#include <memory>

#include "controller.h"

using Date = std::chrono::year_month_day;

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

std::size_t Controller::getPortfoliosNumber() const {
  return m_portfolio_manager->getPortfoliosNumber();
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

void Controller::removeAsset(std::size_t portfolio_index, std::size_t asset_index) {
  Portfolio& portfolio { m_portfolio_manager->getPortfolio(portfolio_index) };
  portfolio.removeAsset(asset_index);
}

void Controller::printAssets(std::size_t portfolio_index) const {
  Portfolio& portfolio { m_portfolio_manager->getPortfolio(portfolio_index) };
  portfolio.printAssets();
}

void Controller::addTransaction(
    std::size_t portfolio_index,
    std::size_t asset_index,
    double quantity,
    double price,
    std::string_view payment_currency,
    Date date) {
  Portfolio& portfolio { m_portfolio_manager->getPortfolio(portfolio_index) };
  Asset& asset { portfolio.getAsset(asset_index) };
  asset.addTransaction(std::make_unique<Transaction>(quantity, price, payment_currency, date));
}

void Controller::removeTransaction(
    std::size_t portfolio_index,
    std::size_t asset_index,
    std::size_t transaction_index) {
  Portfolio& portfolio { m_portfolio_manager->getPortfolio(portfolio_index) };
  Asset& asset { portfolio.getAsset(asset_index) };
  asset.removeTransaction(transaction_index);
}

void Controller::printTransactions(
    std::size_t portfolio_index,
    std::size_t asset_index) const {
  Portfolio& portfolio { m_portfolio_manager->getPortfolio(portfolio_index) };
  Asset& asset { portfolio.getAsset(asset_index) };
  asset.printTransactions();
}

