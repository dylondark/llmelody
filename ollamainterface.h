#ifndef OLLAMAINTERFACE_H
#define OLLAMAINTERFACE_H

#include <string>

using std::string;

class OllamaInterface
{
public:
    OllamaInterface();
    bool ping();

    /*
        Returns whether the object is connected to Ollama or not.
    */
    bool isConnected();

private:
    bool connected;
};

#endif // OLLAMAINTERFACE_H
