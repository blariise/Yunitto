#ifndef ASSET_H
#define ASSET_H

#include <iostream>
#include <string_view>

class Asset {
  public:
    Asset() = delete;
    Asset(std::string_view name, std::string_view ticker, std::string_view type, std::string_view currency);

    const std::string& getName() const;
    const std::string& getTicker() const;
    const std::string& getType() const;
    const std::string& getCurrency() const;
    double getCurrentPrice() const;
  private:
    std::string m_name;
    std::string m_ticker;
    std::string m_type;
    std::string m_currency;
    // transactions vector
    double m_current_price;
 
};
#endif // ASSET_H

