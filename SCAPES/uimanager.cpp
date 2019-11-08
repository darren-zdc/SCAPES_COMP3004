#include "uimanager.h"
#include <mainwindow.h>

void uimanager::RecieveSignal(string signal, QString filename, QString secondaryData) //public signal handler
{
    //TODO setup proper signal handler
    SendSignal(signal, filename, secondaryData);
}

QStringList uimanager::PollProgramList() //communicates with storage to update the ui's program list
{
    return files->programRequest();
}

QStringList uimanager::PollFileContents()
{
    return files->contentsRequest();
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
