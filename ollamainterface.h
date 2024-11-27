#ifndef OLLAMAINTERFACE_H
#define OLLAMAINTERFACE_H

#include <QObject>
#include <QThread>
#include <string>
#include "threadworker.h"

using std::string;

class OllamaInterface : public QObject
{
    Q_OBJECT
public:
    OllamaInterface(string url, string model);

    ~OllamaInterface();

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

    /*
        Prompts the model and begins waiting for response.
    */
    void sendPrompt(string systemPrompt, string userPrompt);

signals:
    void responseReceived(QString response);

private:
    bool connected;
    string url;
    string model;
    QThread requestThread;
    ThreadWorker worker;

    /*
        Callback function to handle the response from the Ollama server.
    */
    static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif // OLLAMAINTERFACE_H
