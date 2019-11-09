#ifndef OPENCONTROL_H
#define OPENCONTROL_H

#include <QString>

class openControl
{
public:
    openControl(QString, int tag);
    QStringList openControlFuncitonality();
private:
    int flag;
    QStringList getFileList();
    QStringList getFileContents();
    //setOpenfile();
};

#endif // OPENCONTROL_H
