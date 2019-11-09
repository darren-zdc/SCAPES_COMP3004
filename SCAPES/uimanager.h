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
private:
    void SendSignal(string signal, QString filename, QString secondaryData);
    //TODO add reference to some form of file manager to get program list and file contents
    filemanager *files = new filemanager;
};

#endif // UIMANAGER_H
