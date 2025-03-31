#include "asset.h"

Asset::Asset(std::string_view name, std::string_view ticker, std::string_view type, std::string_view currency)
  : m_name { name }
  , m_ticker { ticker }
  , m_type { type }
  , m_currency { currency } {}

const std::string& Asset::getName() const { return m_name; }
const std::string& Asset::getTicker() const { return m_ticker; }
const std::string& Asset::getType() const { return m_type; }
const std::string& Asset::getCurrency() const { return m_currency; }
double Asset::getCurrentPrice() const { return m_current_price; }
double Asset::getTotalQuantity() const { return m_total_quantity; }                                      
double Asset::getTotalCost() const { return m_total_cost; }
double Asset::getCurrentValue() const { return m_current_value; }
double Asset::getProfit() const { return m_profit; }

void Asset::calculateProfit() {
  m_profit = m_current_value - m_total_cost;
}

void Asset::calculateCurrentValue() {
  m_current_value += (m_total_quantity * m_current_price);
}

void Asset::addTransaction(const Transaction& transaction) {
  m_total_cost += (transaction.getQuantity() * transaction.getPrice());
  m_total_quantity += transaction.getQuantity();
  calculateCurrentValue();
  calculateProfit();
  m_transactions.push_back(transaction);
}
