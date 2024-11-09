#ifndef OLLAMAINTERFACE_H
#define OLLAMAINTERFACE_H

#include <string>

using std::string;

class OllamaInterface
{
public:
    OllamaInterface();
    bool ping();
    bool isConnected();

private:
    bool connected;
};

#endif // OLLAMAINTERFACE_H
