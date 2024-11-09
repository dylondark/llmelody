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

    /*
        Sets the URL of the Ollama server.
    */
    void setURL(string url);

    /*
        Returns the URL of the Ollama server.
    */
    string getURL();

    /*
        Sets the model to use.
    */
    void setModel(string model);

    /*
        Returns the model to use.
    */
    string getModel();

private:
    bool connected;
    string url;
    string model;
};

#endif // OLLAMAINTERFACE_H
