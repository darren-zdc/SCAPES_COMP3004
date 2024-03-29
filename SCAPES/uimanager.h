#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <filemanager.h>
#include <mainwindow.h>
#include <QTextEdit>
#include <string>

using namespace std;

class MainWindow;

class uimanager
{
public:
    void RecieveSignal(string signal, QString filename, QString secondaryData);
    QStringList PollProgramList();
    QStringList PollFileContents(QString name);
    MainWindow *window;
    QString getDirectory();
    QString getLang();
    int SetDirectory(QString dir, QString user);
    void SetLang(QString lang, QString user);
    void displayMessage(string type, string source);
    void displayOutput(string output);
    int requestInput(string name);
    filemanager* GetFileManager();
    QString openFile;
private:
    void SendSignal(string signal, QString filename, QString secondaryData);
    filemanager *files = new filemanager;
    preferenceManager *pref = files->getPrefManager();
};

#endif // UIMANAGER_H
