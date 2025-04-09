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

double Asset::getQuantity() const { 
  double quantity { 0 };
  for (const auto& t : m_transactions)
    quantity += t->getQuantity();
  return quantity;
}                 

double Asset::getTotalCost() const {
  double total_cost { 0 };
  for (const auto& t : m_transactions)
      total_cost += t->getTotalCost();
  return total_cost;
}

double Asset::getCurrentValue() const {
  return getQuantity() * m_current_price;
}

double Asset::getProfit() const {
   return getCurrentValue() - m_current_price; 
}

void Asset::addTransaction(std::unique_ptr<Transaction> transaction) {
  m_transactions.emplace_back(std::move(transaction));
}

void Asset::removeTransaction(std::size_t transaction_index) {
  if (transaction_index < std::size(m_transactions)) {
    auto transaction { m_transactions.begin() + transaction_index };
    m_transactions.erase(transaction, transaction + 1);
  }
}

void Asset::printTransactions() const {
  std::cout << "Transactions in (" << m_name << "): \n";
  for (const auto& transaction : m_transactions)
    std::cout << transaction->getDate() << '\n';
}

std::size_t Asset::getTransactionsNumber() const {
  return std::size(m_transactions);
}
