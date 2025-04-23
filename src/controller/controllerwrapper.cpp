#include "controllerwrapper.h"
#include <string>
#include <QDebug>

ControllerWrapper::ControllerWrapper(std::unique_ptr<Controller> controller, QObject* parent)
  : QObject { parent }
  , m_controller { std::move(controller) } {}

void ControllerWrapper::addPortfolio(const QString& name) {
  m_controller->addPortfolio(name.toStdString());
  emit portfoliosChanged();
}

void ControllerWrapper::removePortfolio(std::size_t index) {
  m_controller->removePortfolio(index);
  emit portfoliosChanged();
}

int ControllerWrapper::getPortfoliosNumber() const {
  return static_cast<int>(m_controller->getPortfoliosNumber());
}

QString ControllerWrapper::getPortfolioName() const {
  return QString::fromStdString(m_controller->getPortfolioName(m_current_portfolio));
}

double ControllerWrapper::getPortfoliosTotalValue() const {
  return m_controller->getPortfoliosTotalValue();
}

double ControllerWrapper::getPortfolioValue(std::size_t portfolio_index) const {
  return m_controller->getPortfolioValue(portfolio_index);
}

QStringList ControllerWrapper::getPortfoliosList() const {
  QStringList list {};
  const auto& portfolios { m_controller->getPortfolios() };
  for (const auto& portfolio : portfolios)
    list.append(QString::fromStdString(portfolio->getName()));

  return list;
}

void ControllerWrapper::setCurrentPortfolio(std::size_t portfolio_index) {
  m_current_portfolio = portfolio_index;
  emit portfoliosChanged();
}

double ControllerWrapper::getCurrentPortfolioValue() const {
  return getPortfolioValue(m_current_portfolio);
}

void ControllerWrapper::addAsset(
    std::size_t portfolio_index,
    const QString& name,
    const QString& ticker,
    const QString& type,
    const QString& currency) {
  m_controller->addAsset(
      portfolio_index,
      name.toStdString(),
      ticker.toStdString(),
      type.toStdString(),
      currency.toStdString());
  emit portfoliosChanged();
}

void ControllerWrapper::removeAsset(std::size_t portfolio_index, std::size_t asset_index) {
  m_controller->removeAsset(portfolio_index, asset_index);
  emit portfoliosChanged();
}

void ControllerWrapper::setCurrentAsset(std::size_t asset_index) {
  m_current_asset = asset_index;
}

QStringList ControllerWrapper::getAssetsList() const {
  QStringList list {};
  const auto& assets { m_controller->getAssets(m_current_portfolio) };
  for (const auto& asset : assets)
    list.append(QString::fromStdString(asset->getName()));

  return list;
}

void ControllerWrapper::addTransaction(
    int portfolio_index,
    int asset_index,
    QString quantity,
    QString price,
    const QString& type,
    const QString& currency,
    QString day,
    QString month,
    QString year) {

  const std::chrono::year_month_day ymd{
      std::chrono::year{ year.toInt() },
      std::chrono::month{ static_cast<unsigned>(month.toInt()) },
      std::chrono::day{ static_cast<unsigned>(day.toInt()) }
  };
  m_controller->addTransaction(
      portfolio_index,
      asset_index,
      quantity.toDouble(),
      price.toDouble(),
      type.toStdString(),
      currency.toStdString(),
      ymd
  );
  emit portfoliosChanged();
}

void ControllerWrapper::removeTransaction(
    std::size_t portfolio_index,
    std::size_t asset_index,
    std::size_t transaction_index) {
  m_controller->removeTransaction(portfolio_index, asset_index, transaction_index);
  emit portfoliosChanged();
}

QStringList ControllerWrapper::validateAndGetDate(QString date) const {
  std::istringstream iss(date.toStdString());
  std::chrono::year_month_day ymd {};
  iss >> std::chrono::parse("%d-%m-%Y", ymd);
  if (!iss.fail() && ymd.ok()) {
    return {
      QString::number(static_cast<unsigned>(ymd.day())),
      QString::number(static_cast<unsigned>(ymd.month())),
      QString::number(static_cast<int>(ymd.year()))
    };
  }
  return {};
}

QStringList ControllerWrapper::getTransactionsList() const {
  QStringList list {};
  const auto& transactions { m_controller->getTransactions(m_current_portfolio, m_current_asset) };
  for (const auto& transaction : transactions)
    list.append(QString::fromStdString(transaction->getType()));

  return list;
}

QString ControllerWrapper::getAssetName() const {
  return QString::fromStdString(m_controller->getAssetName(m_current_portfolio, m_current_asset));
}

double ControllerWrapper::getCurrentAssetValue() const {
  return m_controller->getAsset(m_current_portfolio, m_current_asset).getCurrentValue();
}
