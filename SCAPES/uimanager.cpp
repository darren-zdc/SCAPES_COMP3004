#include "uimanager.h"

void uimanager::RecieveSignal(string signal, QString filename) //public signal handler
{
    //TODO setup proper signal handler
    SendSignal(signal, filename);
}

QStringList uimanager::PollProgramList() //communicates with storage to update the ui's program list
{
    //TODO talk with file manager
    QStringList temp;
    temp << "file1" << "file2" << "file3";
    return temp;
}

QStringList uimanager::PollFileContents()
{
    //TODO talk with file manager
    QStringList temp;
    temp <<"test line 1" <<"test line 2"<< "test line 3";
    return temp;
}

void uimanager::SendSignal(string signal, QString filename) //private signal handler, communicates with X
{
    //TODO talk with subsystem managers to handle signals
    if (signal == "create")
    {

    }
    else if (signal == "compile")
    {

    }
    else if (signal == "run")
    {

    }
    else if (signal == "save")
    {

    }
    else if (signal == "open")
    {

    }
}
