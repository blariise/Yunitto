#include <iostream>

#include "portfoliomanager.h"
#include "portfolio.h"
#include "asset.h"
#include "transaction.h"

int main() { 

  PortfolioManager pm {};
  auto crypto { std::make_shared<Portfolio>("crypto") };
  pm.addPortfolio(crypto);
  auto btc { std::make_shared<Asset>("Bitcoin", "BTC", "Crypto", "PLN")};
  crypto->addAsset(btc);

  const std::chrono::time_point now{std::chrono::system_clock::now()};
  const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};

  Transaction x {10, 100, "PLN", ymd};
 
  std::cout << btc->getName() << " has: " << btc->getQuantity() << " quantity\n";

  btc->addTransaction(x);

  std::cout << btc->getName() << " has: " << btc->getQuantity() << " quantity\n";

  std::cout << crypto->getName() << '\n';
  std::cout << crypto->getTotalValue() << '\n';
  
  auto eth { std::make_shared<Asset>("Ethereum", "ETH", "Crypto", "PLN") };

  crypto->addAsset(eth);

  eth->addTransaction( {10, 30, "PLN", ymd} );

  std::cout << "crypto porftolio value: " << crypto->getTotalValue() << '\n';
  auto etf { std::make_shared<Portfolio>("etf") };
  pm.addPortfolio(etf);
  auto msci { std::make_shared<Asset>("MSWI", "xd", "etf", "PLN") };
  etf->addAsset(msci);
  msci->addTransaction({10, 130, "PLN", ymd});
  
  std::cout << "etf portfolio value: " << etf->getTotalValue() << '\n';

  std::cout << "All porftolios value: " <<pm.getTotalValue() << '\n';
  return 0;
}

