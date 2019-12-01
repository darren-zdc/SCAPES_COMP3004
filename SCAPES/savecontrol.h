#ifndef SAVECONTROL_H
#define SAVECONTROL_H
#include <QString>
#include <QStringList>
#include <string>
using namespace std;

class savecontrol
{
public:
    savecontrol(QString name, QStringList commands, string dir);
    int saveFile();
private:
    QString filename;
    QStringList contents;
    string directory;
};

#endif // SAVECONTROL_H
