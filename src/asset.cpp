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

