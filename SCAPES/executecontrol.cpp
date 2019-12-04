#include "executecontrol.h"
#include <filemanager.h>

executeControl::executeControl(string file, string dir, filemanager* manager)
{
    this->directory = dir;
    this->name = file;
    this->manager = manager;
}

string executeControl::executeProgram()
{
    //executes a program and collects the output
    program = Program::deserializeToObject(name, directory);
    program->control = this;
    int i = program->Execute();
    if (i == 0)
    {
        manager->sendMessage("Execution Error", "ExecuteControl");
    }
    else
        return program->getProgramOutput();

    return "null"; //will only be reached if program chrashes
}

int executeControl::readInput(string name) //request an integer from the user
{
    return this->manager->requestInput(name);
}
