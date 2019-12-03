#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <QString>
#include <preferencemanager.h>
#include <logger.h>

using namespace std;

class uimanager;

class filemanager
{
public:
    filemanager();
    void recieveSignal(string signal, QString filename, QString secondaryData);
    QStringList programRequest();
    QStringList contentsRequest(QString name);
    preferenceManager* getPrefManager();
    uimanager *ui;
    void setLogger(Logger *log);
    void sendMessage(string message, string source);
private:
    void createCreateControl();
    void createSaveControl(QString name, QStringList contents);
    void createRenameControl(QString name, QString newName);
    void createCompileControl(QString name);
    void createRunControl(QString name);
    QStringList createOpenControl(QString name, int flag);
    preferenceManager *pref = new preferenceManager;
    Logger *log;
};

#endif // FILEMANAGER_H
