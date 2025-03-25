#ifndef ASSET_H
#define ASSET_H

class Asset {
public:
  Asset();
  virtual ~Asset() = default;

private:
  std::string m_name;
  std::string m_ticker;
  double m_current_price;
  double m_current_value;
  double quanity;
};
#endif // ASSET_H

