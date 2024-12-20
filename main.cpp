#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "prompt.h"
#include "programcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    qRegisterMetaType<Prompt>("Prompt");

    // create ProgramController and make it accessible in QML
    ProgramController controller;
    engine.rootContext()->setContextProperty("controller", &controller);

    engine.loadFromModule("llmelody", "Main");

    return app.exec();
}
