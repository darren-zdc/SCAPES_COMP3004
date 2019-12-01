#include "renamecontrol.h"
#include <stdio.h>

renameControl::renameControl(string Filename, string newName, string dir)
{
    this->old = Filename;
    this->name = newName;
    this->directory = dir;
}

int renameControl::renameFile()
{
    old = directory + "/" + old; //setup path names
    name = directory + "/" + name;

    if (name.length() < 5) //name is not long enough to end in .txt
    {
        name.append(".txt");
    }
    else if (name.substr(name.length() -4, name.length() - 1) != ".txt") //name does not end in .txt
    {
        name.append(".txt");
    }

    const char *oldName = old.c_str(); //convert to char
    const char *newName = name.c_str();

    return rename(oldName, newName); //built in c++ function to rename files
}
