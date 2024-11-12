#include "ollamainterface.h"

OllamaInterface::OllamaInterface(string url, string model)
    : connected(false), url(url), model(model)
{
    ping();
}

/*
    Pings the Ollama server to check if it is available.

    Returns whether the ping was successful and sets the connected flag accordingly.
*/
bool OllamaInterface::ping()
{
    return false; // Placeholder
}

/*
    Returns whether the object is connected to Ollama or not.
*/
bool OllamaInterface::isConnected() const
{
    return connected;
}

/*
    Sets the URL of the Ollama server.
*/
void OllamaInterface::setURL(string url)
{
    this->url = url;
}

/*
    Returns the URL of the Ollama server.
*/
string OllamaInterface::getURL() const
{
    return url;
}

/*
    Sets the model to use.
*/
void OllamaInterface::setModel(string model)
{
    this->model = model;
}

/*
    Returns the model to use.
*/
string OllamaInterface::getModel() const
{
    return model;
}
