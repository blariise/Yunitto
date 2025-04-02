#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <chrono>
#include <string>
#include <string_view>

class Transaction {
  public:
    using Date = std::chrono::year_month_day;
    
    Transaction() = delete;
    Transaction(double quantity, double price, std::string_view payment_currency, Date date); 
  
    int getTransactionId() const;
    double getQuantity() const;
    double getPrice() const;
    const std::string& getPaymentCurrency() const;
    const Date getDate() const;
    double getTotalCost() const;

  private:
    double m_quantity;
    double m_price;
    std::string m_payment_currency;
    Date m_date;
   
    double m_total_cost;
    static inline int s_id_generator { 1 };
    int m_transaction_id;
};
#endif // TRANSACTION_H
