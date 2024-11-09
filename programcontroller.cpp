#include "programcontroller.h"

ProgramController::ProgramController(QObject *parent)
    : QObject{parent}
{}

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
