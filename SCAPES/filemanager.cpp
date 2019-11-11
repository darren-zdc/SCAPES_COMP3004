#include "filemanager.h"

#include <QStringList>
#include <createcontrol.h>
#include <opencontrol.h>
#include <savecontrol.h>
#include <compilecontrol.h>

filemanager::filemanager()
{

}

QStringList filemanager::programRequest() //request list of programs
{
    return (createOpenControl("null", 2));
}

QStringList filemanager::contentsRequest(QString name) //request contents of a file
{
    return createOpenControl(name, 1);
}

void filemanager::recieveSignal(string signal, QString filename, QString secondaryData) //signal handler
{
    if (signal == "run")
    {
        createRunControl(filename);
    }
    else if (signal == "open")
    {
        createOpenControl(filename, 1);
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

preferenceManager* filemanager::getPrefManager()
{
    return this->pref;
}

void filemanager::createRunControl(QString name)
{

}

QStringList filemanager::createOpenControl(QString name, int flag) //initiate control flow for opening file list/file contents
{
    openControl *control = new openControl(name, flag, pref->GetDirectory());
    QStringList temp = control->openControlFuncitonality();
    delete control;
    return temp;
}

void filemanager::createSaveControl(QString name, QStringList contents) //initiate control flow fo saving a file
{
    savecontrol *control = new savecontrol(name, contents, pref->GetDirectory());
    control->saveFile();
    delete control;
}

void filemanager::createCreateControl() //initiate control flow for creating a blank file
{
    createControl *control = new createControl(pref->GetDirectory());
    control->createfile();
    delete control;
}

void filemanager::createCompileControl(QString name) //initiate control flow for compiling a program
{
    //compileControl *control = new compileControl();
    //control->compileFile();
    //delete control;
}
