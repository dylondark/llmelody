#ifndef OLLAMAINTERFACE_H
#define OLLAMAINTERFACE_H

#include <string>

using std::string;

class OllamaInterface
{
public:
    OllamaInterface();

    /*
        Pings the Ollama server to check if it is available.

        Returns whether the ping was successful and sets the connected flag accordingly.
    */
    bool ping();

    /*
        Returns whether the object is connected to Ollama or not.
    */
    bool isConnected() const;

    /*
        Sets the URL of the Ollama server.
    */
    void setURL(string url);

    /*
        Returns the URL of the Ollama server.
    */
    string getURL() const;

    /*
        Sets the model to use.
    */
    void setModel(string model);

    /*
        Returns the model to use.
    */
    string getModel() const;

private:
    bool connected;
    string url;
    string model;
};

#endif // OLLAMAINTERFACE_H
