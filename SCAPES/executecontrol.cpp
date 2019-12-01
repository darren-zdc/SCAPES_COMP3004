#include "executecontrol.h"

executeControl::executeControl(string file, string dir)
{
    this->directory = dir;
    this->name = file;
}

string executeControl::executeProgram()
{
    //executes a program and collects the output
    string temp = "Test / of / program / output / handling";
    return temp;
}
