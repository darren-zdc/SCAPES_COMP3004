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

void filemanager::setLogger(Logger *log)
{
    this->log = log;
    this->log->setManager(this);
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
    if (name.endsWith(".json"))
    {
        executeControl *control = new executeControl(name.QString::toStdString(), pref->GetDirectory(), this);
        string output = control->executeProgram();
        control->readInput("test");
        delete control;
        this->ui->displayOutput(output);
    }
    else
    {
        this->ui->displayMessage(to_string(1), "ExecuteControl");
    }
}

QStringList filemanager::createOpenControl(QString name, int flag) //initiate control flow for opening file list/file contents
{
    openControl *control = new openControl(name, flag, pref->GetDirectory());
    QStringList temp = control->openControlFuncitonality();
    delete control;
    return temp;
}

void filemanager::createSaveControl(QString name, QStringList contents) //initiate control flow for saving a file
{
    savecontrol *control = new savecontrol(name, contents, pref->GetDirectory());
    int message = control->saveFile();
    delete control;
    this->ui->displayMessage(to_string(message), "SaveControl");
}

void filemanager::createRenameControl(QString name, QString newName) //initiate control flow to rename a file (only occurs after saving a file)
{
    renameControl *control = new renameControl(name.QString::toStdString(), newName.QString::toStdString(), pref->GetDirectory());
    int message = control->renameFile();
    delete control;
    this->ui->displayMessage(to_string(message), "RenameControl");

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
    this->ui->displayMessage(to_string(message), "CompileControl");
}

void filemanager::sendMessage(string message, string source)
{
    this->ui->displayMessage(message, source);
}

int filemanager::requestInput(string name)
{
    return this->ui->requestInput(name);
}
