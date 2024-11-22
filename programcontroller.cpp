#include "programcontroller.h"

ProgramController::ProgramController(QObject *parent)
    : QObject(parent), ollama("http://localhost:11434", "llama3.2:3b")
{
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
    Prompt the model, decode its output, and prompt user to save.
*/
void ProgramController::generate(const Prompt& prompt)
{

}

/*
    Factory method for creating a new prompt for use in QML.
*/
Prompt ProgramController::createPrompt()
{
    return Prompt();
}
