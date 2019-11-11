#ifndef OPENCONTROL_H
#define OPENCONTROL_H

#include <QString>
#include <string>
using namespace std;

class openControl
{
public:
    openControl(QString name, int tag, string dir);
    QStringList openControlFuncitonality();
private:
    int flag;
    QString name;
    QString directory;
};

#endif // OPENCONTROL_H
