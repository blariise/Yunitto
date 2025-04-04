#ifndef ASSET_H
#define ASSET_H

#include <iostream>
#include <string_view>
#include <vector>
#include <memory>

#include "transaction.h"

class Asset {
  public:
    Asset() = delete;
    Asset(std::string_view name, std::string_view ticker, std::string_view type, std::string_view currency);

    const std::string& getName() const;
    const std::string& getTicker() const;
    const std::string& getType() const;
    const std::string& getCurrency() const;
    double getCurrentPrice() const;

    double getQuantity() const;
    double getTotalCost() const;
    double getCurrentValue() const;
    double getProfit() const;

    void addTransaction(std::unique_ptr<Transaction> transaction);
    void removeTransaction(std::size_t transaction_index);
    void printTransactions() const;

  private:
    std::string m_name;
    std::string m_ticker;
    std::string m_type;
    std::string m_currency;

    double m_current_price { 30 }; // temp value
    std::vector<std::unique_ptr<Transaction>> m_transactions;
};
#endif // ASSET_H

