#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <QString>
#include <preferencemanager.h>

using namespace std;

class filemanager
{
public:
    filemanager();
    void recieveSignal(string signal, QString filename, QString secondaryData);
    QStringList programRequest();
    QStringList contentsRequest(QString name);
    preferenceManager* getPrefManager();
private:
    void createCreateControl();
    void createSaveControl(QString name, QStringList contents);
    void createCompileControl(QString name);
    void createRunControl(QString name);
    QStringList createOpenControl(QString name, int flag);
    preferenceManager *pref = new preferenceManager;
};

#endif // FILEMANAGER_H
