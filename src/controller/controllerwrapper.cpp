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

void ControllerWrapper::printPortfolios() const {
  m_controller->printPortfolios();
}

double ControllerWrapper::getPortfoliosTotalValue() const {
  return m_controller->getPortfoliosTotalValue();
}

QStringList ControllerWrapper::getPortfoliosList() const {
  QStringList list;
  const auto& portfolios { m_controller->getPortfolios() };
  for (const auto& portfolio : portfolios)
    list.append(QString::fromStdString(portfolio->getName()));

  return list;
}

