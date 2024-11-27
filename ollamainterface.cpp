#include "ollamainterface.h"
#include <iostream>
#include <curl/curl.h>

OllamaInterface::OllamaInterface(string url, string model)
    : connected(false), url(url), model(model)
{
    worker.moveToThread(&requestThread);
    requestThread.start();
}

OllamaInterface::~OllamaInterface()
{
    requestThread.quit();
    requestThread.wait();
}

/*
    Pings the Ollama server to check if it is available.

    Returns whether the ping was successful and sets the connected flag accordingly.
*/
bool OllamaInterface::ping()
{
    CURL *curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, (url + "/ping").c_str());
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK)
        {
            connected = true;
        }
        else
        {
            connected = false;
        }
        curl_easy_cleanup(curl);
    }
    return connected;
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

/*
    Prompts the model and begins waiting for response.
*/
void OllamaInterface::sendPrompt(string systemPrompt, string userPrompt)
{
    QMetaObject::invokeMethod(&worker, [=]() {
        // make the prompt request
        CURL *curl = curl_easy_init();
        CURLcode res;
        if (curl)
        {
            // Set the URL
            string thisUrl = url + "/api/chat";
            curl_easy_setopt(curl, CURLOPT_URL, thisUrl.c_str());

            // Set the HTTP POST data
            string data = R"({
        "model": ")" + model + R"(",
        "messages": [
            {
                "role": "system",
                "content": ")" + systemPrompt + R"("
            },
            {
                "role": "user",
                "content": ")" + userPrompt + R"("
            }
        ],
        "stream": false
    })";

            // Set headers for JSON content
            struct curl_slist *headers = nullptr;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            // Attach the JSON data
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

            // Set the callback function to capture the response
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

            // Pass the std::string to store the response
            string response;
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            // Make the request
            res = curl_easy_perform(curl);

            // Check for errors
            if (res != CURLE_OK) {
                std::cerr << "cURL error: " << curl_easy_strerror(res) << "\n";
            } else {
                // Print the response
                std::cout << "Response from server: " << response << "\n";
            }

            // Cleanup
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);

            // Emit the response
            emit responseReceived(QString::fromStdString(response));
        }
    });
}

/*
    Callback function to handle the response from the Ollama server.
*/
size_t OllamaInterface::writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    string *response = static_cast<string *>(userp);
    response->append(static_cast<char *>(contents), realsize);
    return realsize;
}
