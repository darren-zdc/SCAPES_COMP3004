#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <QString>

using namespace std;

class filemanager
{
public:
    filemanager();
    void recieveSignal(string signal, QString filename, QString secondaryData);
    QStringList programRequest();
    QStringList contentsRequest(QString name);
private:
    void createCreateControl();
    void createSaveControl(QString name, QStringList contents);
    void createCompileControl(QString name);
    void createRunControl(QString name);
    QStringList createOpenControl(QString name, int flag);
};

#endif // FILEMANAGER_H
