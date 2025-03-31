#include "transaction.h"

using Date = std::chrono::year_month_day;

Transaction::Transaction(double quantity, double price, std::string_view payment_currency, Date date)
  : m_quantity { quantity }
  , m_price { price }
  , m_payment_currency { payment_currency }
  , m_date { date }
  , m_transaction_id { s_id_generator++ } {}

int Transaction::getTransactionId() const { return m_transaction_id; }
double Transaction::getQuantity() const { return m_quantity; }
double Transaction::getPrice() const { return m_price; }
const std::string& Transaction::getPaymentCurrency() const { return m_payment_currency; }
const Date Transaction::getDate() const { return m_date; }
