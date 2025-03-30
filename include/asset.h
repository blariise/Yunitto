#ifndef ASSET_H
#define ASSET_H

class Asset {
public:
  Asset() = delete;
  Asset(std::string_view name, std::string_view ticker, std::string_view type, double currency);

  std::string& getName() const;
  std::string& getTicker() const;
  std::string& getType() const;
  double getCurrentPrice() const;
  double getCurrency() const;
private:
  std::string m_name;
  std::string m_ticker;
  std::string m_type;
  // transactions vector
  double m_current_price;
  double m_currency;
};
#endif // ASSET_H

