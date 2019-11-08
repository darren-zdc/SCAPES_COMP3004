#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QTextEdit>
#include <string>

using namespace std;

class uimanager
{
public:
    void RecieveSignal(string signal, QString filename);
    QStringList PollProgramList();
    QStringList PollFileContents();
private:
    void SendSignal(string signal, QString filename);
    //TODO add reference to some form of file manager to get program list and file contents
};

#endif // UIMANAGER_H
