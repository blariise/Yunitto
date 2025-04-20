#include "controllerwrapper.h"

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
  emit assetsChanged();
}

void ControllerWrapper::removeAsset(std::size_t portfolio_index, std::size_t asset_index) {
  m_controller->removeAsset(portfolio_index, asset_index);
  emit assetsChanged();
}

QStringList ControllerWrapper::getAssetsList() const {
  QStringList list {};
  const auto& assets { m_controller->getAssets(m_current_portfolio) };
  for (const auto& asset : assets)
    list.append(QString::fromStdString(asset->getName()));

  return list;
}
