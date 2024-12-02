#include "programcontroller.h"
#include <nlohmann/json.hpp>
#include <iostream>

ProgramController::ProgramController(QObject *parent)
    : QObject(parent), ollama("http://localhost:11434", "llama3.2:3b")
{
    connect(&ollama, &OllamaInterface::responseReceived, this, &ProgramController::onGenerateFinished);
}

/*
    Sets the URL of the Ollama server.
*/
void ProgramController::setURL(QString url)
{
    ollama.setURL(url.toStdString());
}

/*
    Returns the URL of the Ollama server.
*/
QString ProgramController::getURL() const
{
    return QString::fromStdString(ollama.getURL());
}

/*
    Sets the model to use.
*/
void ProgramController::setModel(QString model)
{
    ollama.setModel(model.toStdString());
}

/*
    Returns the model to use.
*/
QString ProgramController::getModel() const
{
    return QString::fromStdString(ollama.getModel());
}

/*
    Pings the Ollama server and returns the status.
*/
bool ProgramController::pingOllama()
{
    return ollama.ping();
}

/*
    Returns whether the Ollama server is connected.
*/
bool ProgramController::getOllamaStatus()
{
    return ollama.isConnected();
}

/*
    Prompt the model and begin waiting on response.
*/
void ProgramController::generate(const Prompt& prompt)
{
    ollama.sendPrompt(prompt.getSystemPrompt().toStdString(), prompt.getUserPrompt().toStdString());
    lastPrompt = prompt;
}

/*
    Factory method for creating a new prompt for use in QML.
*/
Prompt ProgramController::createPrompt()
{
    return Prompt();
}

/*
    Slot to be called when Ollama finishes generating a response.
    Decodes the output and then invokes abc2midi to convert the output to a MIDI file.
*/
void ProgramController::onGenerateFinished(QString response)
{
    // parse the response
    try
    {
        nlohmann::json json_obj = nlohmann::json::parse(response.toStdString());
        QString content = QString::fromStdString(json_obj["message"]["content"].get<std::string>());

        // invoke abc2midi to convert to midi
        // get application directory
        QString appDir = QCoreApplication::applicationDirPath();
        QProcess abc2midi;
        abc2midi.start("abc2midi", QStringList() << "-" << "-o" << lastPrompt.destFile);
        abc2midi.write(content.toStdString().c_str());
        abc2midi.closeWriteChannel();
        abc2midi.waitForFinished();
        // forward output to console
        std::cout << "abc2midi out: " << abc2midi.readAllStandardOutput().toStdString() << "\n";
        abc2midi.close();
    }
    catch (...)
    {
        emit promptParserError(response);
        return;
    }

    emit generateFinished(response);
}
