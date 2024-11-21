#ifndef PROMPT_H
#define PROMPT_H

#include <string>

using std::string;

struct Prompt
{
    string instrument;
    int tempo;
    int timeSignatureNumerator;
    int timeSignatureDenominator;
    int length;
    char keySignature;
    bool keyMinor;
    string mood;
    string part;
    string genre;
    string extraInfo;

    string getSystemPrompt()
    {
        string prompt = ("You will be asked to write individual instrument parts for songs. You will be given information about the song including its tempo, time signature, and mood. You will be given information about the individual part you are to write, such as its length in measures, instrument it is for, and what part of the song it is for (i.e. chorus, verse, etc). You are to respond with the part written in the following format for every note: '[note],[octave],[duration],[velocity],[start_time]'. The output will be parsed to MIDI. Output only the notes and assume every new prompt is for a new song.\n");
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
    };

    string getUserPrompt()
    {
        string prompt = ("The user has requested a part for a ");
        prompt.append(instrument);
        prompt.append(". The tempo for the song is ");
        prompt.append(std::to_string(tempo));
        prompt.append(". The time signature for the song is ");
        prompt.append(std::to_string(timeSignatureNumerator));
        prompt.append("/");
        prompt.append(std::to_string(timeSignatureDenominator));
        prompt.append(". The length of the part is ");
        prompt.append(std::to_string(length));
        prompt.append(" measures. The key signature for the song is ");
        prompt.append(1, keySignature);
        prompt.append(keyMinor ? " minor. " : " major. ");
        prompt.append("The mood of the song is ");
        prompt.append(mood);
        prompt.append(". The part is for the ");
        prompt.append(part);
        prompt.append(" of the song. The genre of the song is ");
        prompt.append(genre);
        prompt.append(". ");
        if (!extraInfo.empty())
        {
            prompt.append("The user has provided the following additional info: ");
            prompt.append(extraInfo);
        }

        return prompt;
    }
};

#endif // PROMPT_H