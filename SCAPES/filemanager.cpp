#include "filemanager.h"

#include <QStringList>
#include <createcontrol.h>
#include <opencontrol.h>
#include <savecontrol.h>
#include <compilecontrol.h>
#include <renamecontrol.h>
#include <executecontrol.h>
#include <uimanager.h>

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
    else if (signal == "rename")
    {
        createRenameControl(filename, secondaryData);
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

void filemanager::createRunControl(QString name) //initiate control flow to execute a program
{
    executeControl *control = new executeControl();

    delete control;
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
    int message = control->saveFile();
    delete control;
    this->ui->displayMessage(message, "SaveControl");
}

void filemanager::createRenameControl(QString name, QString newName) //initiate control flow to rename a file (only occurs after saving a file)
{
    renameControl *control = new renameControl(name.QString::toStdString(), newName.QString::toStdString(), pref->GetDirectory());
    int message = control->renameFile();
    delete control;
    this->ui->displayMessage(message, "RenameControl");

}

void filemanager::createCreateControl() //initiate control flow for creating a blank file
{
    createControl *control = new createControl(pref->GetDirectory());
    control->createfile();
    delete control;
}

void filemanager::createCompileControl(QString name) //initiate control flow for compiling a program
{
    compileControl *control = new compileControl(name, pref->GetDirectory());
    int message = control->compile();
    delete control;
    this->ui->displayMessage(message, "CompileControl");
}
