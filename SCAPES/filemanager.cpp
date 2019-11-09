#include "filemanager.h"

#include <QStringList>
#include <createcontrol.h>
#include <opencontrol.h>

filemanager::filemanager()
{

}

QStringList filemanager::programRequest()
{
    return (createOpenControl("null", 2));
}

QStringList filemanager::contentsRequest()
{
    return createOpenControl("null", 1);
}

void filemanager::recieveSignal(string signal, QString filename, QString secondaryData)
{
    if (signal == "run")
    {
        createRunControl(filename);
    }
    else if (signal == "open")
    {
        createOpenControl(filename, 0);
    }
    else if (signal == "save")
    {
        QStringList commands = secondaryData.split(QRegExp("[\n]"), QString::SkipEmptyParts);
        createSaveControl(filename, commands);
    }
    else if (signal == "create")
    {
        createCreateControl();
    }
    else if (signal == "compile")
    {
        createCompileControl(filename);
    }
}

void filemanager::createRunControl(QString name)
{

}

QStringList filemanager::createOpenControl(QString name, int flag)
{
    //flag of 0 means just set the file to "open"
    //flag of 1 means return contents of open file
    //flag of 2 means return list of all files

    //QStringList temp;
    //if (flag == 2)
    //{
      //  temp << "file1" << "file2" << "file3";
    //}
    //else if (flag == 1)
    //{
      //  temp << "test line 1" << "test line 2" << "test line 3";
    //}
    //return temp;
    openControl *control = new openControl(name, flag);
    control->openControlFuncitonality();
    QStringList temp = control->openControlFuncitonality();
    delete control;
    return temp;
}

void filemanager::createSaveControl(QString name, QStringList contents)
{

}

void filemanager::createCreateControl()
{
    //createControl *control = new createControl;
    //control->createfile();
    //delete control;
}

void filemanager::createCompileControl(QString name)
{

}
