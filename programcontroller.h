#ifndef PROGRAMCONTROLLER_H
#define PROGRAMCONTROLLER_H

#include <QObject>

/*
    Serves as the interface to C++ from QML.
*/
class ProgramController : public QObject
{
    Q_OBJECT
public:
    explicit ProgramController(QObject *parent = nullptr);

};

#endif // PROGRAMCONTROLLER_H
