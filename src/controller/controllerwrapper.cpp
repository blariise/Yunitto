#include "controllerwrapper.h"

ControllerWrapper::ControllerWrapper(std::unique_ptr<Controller> controller, QObject* parent)
  : QObject { parent }
  , m_controller { std::move(controller) } {}

void ControllerWrapper::addPortfolio(const QString& name) {
  m_controller->addPortfolio(name.toStdString());
}

void ControllerWrapper::removePortfolio(std::size_t index) {
    m_controller->removePortfolio(index);
}

int ControllerWrapper::getPortfoliosNumber() const {
    return static_cast<int>(m_controller->getPortfoliosNumber());
}

void ControllerWrapper::printPortfolios() const {
    m_controller->printPortfolios();
}

