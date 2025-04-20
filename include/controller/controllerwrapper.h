#ifndef CONTROLLERWRAPPER_H
#define CONTROLLERWRAPPER_H

#include <QObject>
#include "controller.h"

class ControllerWrapper : public QObject {
  Q_OBJECT
  Q_PROPERTY(QStringList portfolios READ getPortfoliosList NOTIFY portfoliosChanged)
  Q_PROPERTY(double total_value READ getPortfoliosTotalValue NOTIFY portfoliosChanged)
  Q_PROPERTY(int portfolios_number READ getPortfoliosNumber NOTIFY portfoliosChanged)
  Q_PROPERTY(QString portfolio_name READ getPortfolioName NOTIFY portfoliosChanged)

  Q_PROPERTY(QStringList assets READ getAssetsList NOTIFY assetsChanged)

  public:
    explicit ControllerWrapper(std::unique_ptr<Controller> controller, QObject* parent = nullptr);

    // PORTFOLIO FUNCTIONS
    Q_INVOKABLE void addPortfolio(const QString& name);
    Q_INVOKABLE void removePortfolio(std::size_t index);
    Q_INVOKABLE void setCurrentPortfolio(std::size_t portfolio_index);

    QString getPortfolioName() const;
    int getPortfoliosNumber() const;
    double getPortfoliosTotalValue() const;
    QStringList getPortfoliosList() const;


    // ASSET FUNCTIONS
    Q_INVOKABLE void addAsset(
        std::size_t portfolio_index,
        const QString& name,
        const QString& ticker,
        const QString& type,
        const QString& currency);
    Q_INVOKABLE void removeAsset(std::size_t portfolio_index, std::size_t asset_index);

    QStringList getAssetsList() const;
  signals:
    void portfoliosChanged();
    void assetsChanged();

  private:
    std::size_t m_current_portfolio {};
    std::size_t m_current_asset {};
    std::unique_ptr<Controller> m_controller;
};
#endif // CONTROLLERWRAPPER_H
