#include "ollamainterface.h"

OllamaInterface::OllamaInterface() {}

/*
    Returns whether the object is connected to Ollama or not.
*/
bool OllamaInterface::isConnected()
{
    return connected;
}
