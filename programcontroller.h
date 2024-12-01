#ifndef PROGRAMCONTROLLER_H
#define PROGRAMCONTROLLER_H

#include <QObject>
#include <QString>
#include <QtQmlIntegration>
#include "prompt.h"
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
        Prompt the model and begin waiting on response.
    */
    Q_INVOKABLE void generate(const Prompt& prompt);

    /*
        Factory method for creating a new prompt for use in QML.
    */
    Q_INVOKABLE Prompt createPrompt();

signals:
    /*
        Signal to be emitted when Ollama finishes generating a response to pass the response on to QML.
    */
    void generateFinished(QString response);

private slots:
    /*
        Slot to be called when Ollama finishes generating a response.
        Decodes the output and then invokes abc2midi to convert the output to a MIDI file.
    */
    void onGenerateFinished(QString response);

private:
    OllamaInterface ollama;
    Prompt lastPrompt;
};

#endif // PROGRAMCONTROLLER_H
