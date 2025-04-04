#include "transaction.h"

using Date = std::chrono::year_month_day;

Transaction::Transaction(double quantity, double price, std::string_view payment_currency, Date date)
  : m_quantity { quantity }
  , m_price { price }
  , m_payment_currency { payment_currency }
  , m_date { date }
  , m_total_cost { m_quantity * m_price } {}

double Transaction::getQuantity() const { return m_quantity; }
double Transaction::getPrice() const { return m_price; }
const std::string& Transaction::getPaymentCurrency() const { return m_payment_currency; }
const Date Transaction::getDate() const { return m_date; }
double Transaction::getTotalCost() const { return m_total_cost; }

