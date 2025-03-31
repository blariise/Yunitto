#ifndef ASSET_H
#define ASSET_H

#include <iostream>
#include <string_view>
#include <vector>

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
    double getTotalQuantity() const;
    
    void addTransaction(const Transaction& transaction);
  private:
    std::string m_name;
    std::string m_ticker;
    std::string m_type;
    std::string m_currency;
    double m_current_price;
    std::vector<Transaction> m_transactions;
    double m_total_quantity;
};
#endif // ASSET_H

