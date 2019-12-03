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
    program->Execute();
    string temp = "Test # of # program # output # handling";
    return temp;
}

int executeControl::readInput(string name)
{
    return this->manager->requestInput(name);
}
