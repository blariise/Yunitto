#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controllerwrapper.h"
#include "controller.h"  // Assuming this is your main controller class

#include <QDirIterator>
#include <QDebug>
#include <QUrl>

void listQRCResources(const QString& path = QStringLiteral(":/")) {
  QDirIterator it(path, QDirIterator::Subdirectories);
  while (it.hasNext())
    qDebug() << "QRC file:" << it.next();
}

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  // Create Controller instance and wrap it
  auto portfolio_manager { std::make_unique<PortfolioManager>() };
  auto controller { std::make_unique<Controller>(std::move(portfolio_manager)) };
  ControllerWrapper controllerWrapper { std::move(controller) };

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("controller", &controllerWrapper);
  listQRCResources();
  engine.load(QUrl(QStringLiteral("qrc:resources/qml/main.qml")));
  return app.exec();
}

