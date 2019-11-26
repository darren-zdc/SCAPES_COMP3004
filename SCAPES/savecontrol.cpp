#include "savecontrol.h"
#include <Save.h>

savecontrol::savecontrol(QString name, QStringList commands, string dir) //setup valid working variables
{
    if (name.endsWith(".txt"))
    {
        this->filename = name;
    }
    else
    {
        this->filename = name + ".txt";
    }
    this->contents = commands;
    this->directory = dir;
}

int savecontrol::saveFile() //parse given commands into vector of strings, and save them accordingly
{
    string name = filename.QString::toStdString();

    vector<string> commands(contents.size());
    for(int i = 0; i < contents.size(); i++)
    {
        commands[i] = contents[i].QString::toStdString();
    }
    Save *temp = new Save(name, commands, directory);
    delete temp;
    return 1;
}
