#ifndef PROGRAMCONTROLLER_H
#define PROGRAMCONTROLLER_H

#include <QObject>
#include <QString>
#include <QtQmlIntegration>
#include "ollamainterface.h"

/*
    Serves as the interface to C++ from QML.
*/
class ProgramController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit ProgramController(QObject *parent = nullptr);

    /*
        Sets the URL of the Ollama server.
    */
    Q_INVOKABLE void setURL(QString url);

    /*
        Returns the URL of the Ollama server.
    */
    Q_INVOKABLE QString getURL() const;

    /*
        Sets the model to use.
    */
    Q_INVOKABLE void setModel(QString model);

    /*
        Returns the model to use.
    */
    Q_INVOKABLE QString getModel() const;

    /*
        Pings the Ollama server and returns the status.
    */
    Q_INVOKABLE bool pingOllama();

    /*
        Returns whether the Ollama server is connected.
    */
    Q_INVOKABLE bool getOllamaStatus();

    /*
        Prompt the model, decode its output, and prompt user to save.
    */
    Q_INVOKABLE void generate();

private:
    OllamaInterface ollama;
};

#endif // PROGRAMCONTROLLER_H
