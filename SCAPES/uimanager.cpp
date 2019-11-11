#include "uimanager.h"
#include <mainwindow.h>

void uimanager::RecieveSignal(string signal, QString filename, QString secondaryData) //public signal handler
{
    //TODO setup proper signal handler
    SendSignal(signal, filename, secondaryData);
}

QStringList uimanager::PollProgramList() //communicates with storage to update the ui's program list
{
    QStringList fileList = files->programRequest();
    QStringList names;
    for (int i = 0; i < fileList.size(); i++)
    {
        QStringList temp = fileList[i].split(("/"), QString::SkipEmptyParts);
        if (temp[temp.size()-1] != "." && temp[temp.size()-1] != "..")
        {
            names.append(temp[temp.size()-1]);
        }
    }
    return names;
}

QStringList uimanager::PollFileContents(QString name)
{
    return files->contentsRequest(name);
}

QString uimanager::getDirectory()
{
    QString temp = QString::fromStdString(pref->GetDirectory());
    return temp;
}

QString uimanager::getLang()
{
    QString temp = QString::fromStdString(pref->GetDirectory());
    return temp;
}

void uimanager::SetDirectory(QString dir, QString user)
{
    pref->SetDirectory(dir.QString::toStdString(), user.QString::toStdString());
}

void uimanager::SetLang(QString lang, QString user)
{
    pref->SetLang(lang.QString::toStdString(), user.QString::toStdString());
}

void uimanager::SendSignal(string signal, QString filename, QString secondaryData) //private signal handler, communicates with X
{
    if (signal == "create")
    {
        files->recieveSignal(signal, filename, secondaryData);
    }
    else if (signal == "compile")
    {
        files->recieveSignal(signal, filename, secondaryData);
    }
    else if (signal == "run")
    {
        files->recieveSignal(signal, filename, secondaryData);
    }
    else if (signal == "save")
    {
        files->recieveSignal(signal, filename, secondaryData);
    }
    else if (signal == "open")
    {
        files->recieveSignal(signal, filename, secondaryData);
    }
}
