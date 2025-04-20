#ifndef CONTROLLERWRAPPER_H
#define CONTROLLERWRAPPER_H

#include <QObject>
#include "controller.h"

class ControllerWrapper : public QObject {
  Q_OBJECT
  Q_PROPERTY(QStringList portfolios READ getPortfoliosList NOTIFY portfoliosChanged)
  Q_PROPERTY(double total_value READ getPortfoliosTotalValue NOTIFY portfoliosChanged)
  Q_PROPERTY(int portfolios_number READ getPortfoliosNumber NOTIFY portfoliosChanged)

  public:
    explicit ControllerWrapper(std::unique_ptr<Controller> controller, QObject* parent = nullptr);
      
    Q_INVOKABLE void addPortfolio(const QString& name);
    Q_INVOKABLE void removePortfolio(std::size_t index);
    Q_INVOKABLE int getPortfoliosNumber() const;
    Q_INVOKABLE void printPortfolios() const;

    double getPortfoliosTotalValue() const;
    QStringList getPortfoliosList() const;

  signals:
    void portfoliosChanged();

  private:
    std::unique_ptr<Controller> m_controller;
};
#endif // CONTROLLERWRAPPER_H
