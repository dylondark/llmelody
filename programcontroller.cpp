#include "programcontroller.h"

ProgramController::ProgramController(QObject *parent)
    : QObject(parent), ollama("http://localhost:11434", "llama3.2:3b"), systemPrompt(createSystemPrompt())
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
void ProgramController::generate()
{
    // placeholder
}

/*
    Assemble the system prompt.
*/
QString ProgramController::createSystemPrompt()
{
    QString prompt = ("You will be asked to write individual instrument parts for songs. You will be given information about the song including its tempo, time signature, and mood. You will be given information about the individual part you are to write, such as its length in measures, instrument it is for, and what part of the song it is for (i.e. chorus, verse, etc). You are to respond with the part written in the following format for every note: '[note],[octave],[duration],[velocity],[start_time]'. The output will be parsed to MIDI. Output only the notes and assume every new prompt is for a new song.\n");
    prompt.append("The following is using the format\n");
    prompt.append("C,4,1/4,100,0 | E,4,1/4,100,0 | G,4,1/4,100,0  # C major chord, quarter note, starts at beat 0\n");
    prompt.append("G,5,1/4,100,1/4                               # G5 single note, quarter note, starts at beat 1/4\n");
    prompt.append("R,0,1/4,0,1/2                                 # Rest for quarter note, starts at beat 1/2\n");
    prompt.append("F,4,1/4,100,3/4                               # F4 single note, quarter note, starts at beat 3/4\n\n");
    prompt.append("A,4,1/4,100,1 | C,5,1/4,100,1 | E,5,1/4,100,1  # A minor chord, quarter note, starts at beat 1\n");
    prompt.append("R,0,1/4,0,5/4                                 # Rest for quarter note, starts at beat 5/4\n");
    prompt.append("G,4,1/4,100,3/2                               # G4 single note, quarter note, starts at beat 3/2\n");
    prompt.append("B,4,1/4,100,7/4                               # B4 single note, quarter note, starts at beat 7/4\n");

    return prompt;
}
