#ifndef OPENCONTROL_H
#define OPENCONTROL_H

#include <QString>

class openControl
{
public:
    openControl(QString name, int tag);
    QStringList openControlFuncitonality();
private:
    int flag;
    QString name;
    QStringList getFileList();
    QStringList getFileContents();
    //setOpenfile();
};

#endif // OPENCONTROL_H
