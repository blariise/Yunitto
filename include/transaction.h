#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
publid:
  enum Type {
    buy,
    sell,
    max_types
  };
  assert(Type::max_types == 2);
private:
  static std::string m_transaction_id;
  Asset asset;
  Type m_transaction_type;
  double m_quantity;
  double m_price;
};

#endif // TRANSACTION_H

