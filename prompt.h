#ifndef PROMPT_H
#define PROMPT_H

#include <QObject>
#include <QString>
#include <QProcess>

struct Prompt {
    Q_GADGET

    // Properties for QML
    Q_PROPERTY(QString recomposeFile MEMBER recomposeFile)
    Q_PROPERTY(QString instrument MEMBER instrument)
    Q_PROPERTY(int tempo MEMBER tempo)
    Q_PROPERTY(int timeSignatureNumerator MEMBER timeSignatureNumerator)
    Q_PROPERTY(int timeSignatureDenominator MEMBER timeSignatureDenominator)
    Q_PROPERTY(int length MEMBER length)
    Q_PROPERTY(QString keySignature MEMBER keySignature)
    Q_PROPERTY(bool keyMinor MEMBER keyMinor)
    Q_PROPERTY(QString mood MEMBER mood)
    Q_PROPERTY(QString part MEMBER part)
    Q_PROPERTY(QString genre MEMBER genre)
    Q_PROPERTY(QString extraInfo MEMBER extraInfo)
    Q_PROPERTY(QString destFile MEMBER destFile)

public:
    QString recomposeFile;
    QString instrument;
    int tempo;
    int timeSignatureNumerator;
    int timeSignatureDenominator;
    int length;
    QString keySignature;
    bool keyMinor;
    QString mood;
    QString part;
    QString genre;
    QString extraInfo;
    QString destFile;

    QString getSystemPrompt() const
    {
        QString prompt;
        if (recomposeFile == "")
            prompt = "You will be asked to write individual instrument parts for songs. You are to respond with the output in ABC musical notation format. Output ONLY the ABC information.";
        else
            prompt = "You will be given an instrument part in ABC notation. You are to recompose the part with the information given. Respond with the output in ABC musical notation format. Output ONLY the ABC information.";
        return prompt;
    };

    QString getUserPrompt() const
    {
        QString prompt = recomposeFile == "" ? "The user has requested a part for a " : "The user has requested to recompose a part for a ";
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
        prompt.append(keySignature);
        prompt.append(keyMinor ? " minor. " : " major. ");
        prompt.append("The mood of the song is ");
        prompt.append(mood);
        prompt.append(". The part is for the ");
        prompt.append(part);
        prompt.append(" of the song. The genre of the song is ");
        prompt.append(genre);
        prompt.append(". ");
        if (!extraInfo.isEmpty())
        {
            prompt.append("The user has provided the following additional info: ");
            prompt.append(extraInfo);
        }
        if (recomposeFile != "")
        {
            prompt.append("\\nHere is the part to recompose in ABC form: ");
            QProcess midi2abc;
            midi2abc.start("midi2abc", QStringList() << recomposeFile);
            midi2abc.waitForFinished();
            prompt.append(QString(midi2abc.readAllStandardOutput()).replace("\n", "\\n"));
            midi2abc.close();
        }

        return prompt;
    }
};

Q_DECLARE_METATYPE(Prompt)

#endif // PROMPT_H
