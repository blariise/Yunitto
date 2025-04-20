#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controllerwrapper.h"
#include "controller.h"

#include <QDirIterator>
#include <QDebug>
#include <QUrl>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  const std::chrono::time_point now{std::chrono::system_clock::now()};
  const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};

  auto portfolio_manager { std::make_unique<PortfolioManager>() };
  auto controller { std::make_unique<Controller>(std::move(portfolio_manager)) };
  ControllerWrapper controllerWrapper { std::move(controller) };

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("controller", &controllerWrapper);
  engine.load(QUrl(QStringLiteral("qrc:resources/qml/main.qml")));
  return app.exec();
}

