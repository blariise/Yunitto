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
  Q_PROPERTY(double portfolio_value READ getCurrentPortfolioValue NOTIFY portfoliosChanged)

  Q_PROPERTY(QStringList assets READ getAssetsList NOTIFY assetsChanged)

  public:
    explicit ControllerWrapper(std::unique_ptr<Controller> controller, QObject* parent = nullptr);

    // PORTFOLIO FUNCTIONS
    Q_INVOKABLE void addPortfolio(const QString& name);
    Q_INVOKABLE void removePortfolio(std::size_t index);
    Q_INVOKABLE void setCurrentPortfolio(std::size_t portfolio_index);
    Q_INVOKABLE double getPortfolioValue(std::size_t portfolio_index) const;

    QString getPortfolioName() const;
    int getPortfoliosNumber() const;
    double getPortfoliosTotalValue() const;
    QStringList getPortfoliosList() const;
    double getCurrentPortfolioValue() const;

    // ASSET FUNCTIONS
    Q_INVOKABLE void addAsset(
        std::size_t portfolio_index,
        const QString& name,
        const QString& ticker,
        const QString& type,
        const QString& currency);
    Q_INVOKABLE void removeAsset(std::size_t portfolio_index, std::size_t asset_index);

    // if date is valid return QStringList [day, month, year]; elese return empty QStringList
    Q_INVOKABLE QStringList validateAndGetDate(QString date) const;

    QStringList getAssetsList() const;

    Q_INVOKABLE void addTransaction(
        std::size_t portfolio_index,
        std::size_t asset_index,
        double quantity,
        double price,
        std::string_view type,
        std::string_view currency,
        int day,
        int month,
        int year);

  signals:
    void portfoliosChanged();
    void assetsChanged();

  private:
    std::size_t m_current_portfolio {};
    std::size_t m_current_asset {};
    std::unique_ptr<Controller> m_controller;
};
#endif // CONTROLLERWRAPPER_H
