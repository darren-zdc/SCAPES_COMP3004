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

QStringList uimanager::PollFileContents(QString name) //return contents of requested file
{
    return files->contentsRequest(name);
}

QString uimanager::getDirectory() //ask preference manager for current directory
{
    QString temp = QString::fromStdString(pref->GetDirectory());
    return temp;
}

QString uimanager::getLang() //ask preference manager for current language
{
    QString temp = QString::fromStdString(pref->GetDirectory());
    return temp;
}

void uimanager::SetDirectory(QString dir, QString user) //tell preference manager to change the directory
{
    pref->SetDirectory(dir.QString::toStdString(), user.QString::toStdString());
}

void uimanager::SetLang(QString lang, QString user) //tell the preferences manager to change the language
{
    pref->SetLang(lang.QString::toStdString(), user.QString::toStdString());
}

void uimanager::SendSignal(string signal, QString filename, QString secondaryData) //private signal handler, communicates with file manager
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
        files->recieveSignal(signal, openFile, secondaryData);
    }
    else if (signal == "rename")
    {
        if (secondaryData != openFile)
        {
            files->recieveSignal(signal, openFile, secondaryData);
        }
    }
    else if (signal == "open")
    {
        files->recieveSignal(signal, filename, secondaryData);
    }

}

void uimanager::displayMessage(string type, string source) //display pop-up messages to the user
{
    if (source == "CompileControl")
    {
        if (type == "0")
        {
            window->displayInBox("Compiler Error: Aborting");
        }
        else if (type == "1")
        {
            window->displayInBox("Program Compiled Successfully");
        }
    }
    else if (source == "SaveControl")
    {
        if (type == "0")
        {
            window->displayInBox("Save Request Failed");
        }
        else if (type == "1")
        {
            window->displayInBox("File Saved Successfully");
        }
    }
    else if (source == "RenameControl")
    {
        if (type != "0")
        {
            window->displayInBox("Failed to Rename File");
        }
        else
        {
            window->displayInBox("Renamed File");
        }
    }
    else if (source == "ExecuteControl")
    {
        window->displayInBox("Execution Error: Invalid File Type");
    }
    else if (source == "Logger")
    {
        QString temp = QString::fromStdString(type);
        //QStringList display = temp.split("#");
        //window->displayInPopup(display, QString::fromStdString("Logger"));
        window->displayLoggerMessage(temp);
    }
}

filemanager* uimanager::GetFileManager()
{
    return this->files;
}

void uimanager::displayOutput(string output)
{
    QString temp = QString::fromStdString(output);
    QStringList display = temp.split("#");
    window->displayInPopup(display, QString::fromStdString("Program"));
}

int uimanager::requestInput(string name)
{
    QString temp = QString::fromStdString(name);
    return window->requestInput(temp);
}
