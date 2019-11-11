#include "savecontrol.h"
#include <Save.h>

savecontrol::savecontrol(QString name, QStringList commands, string dir)
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

void savecontrol::saveFile()
{
    string name = filename.QString::toStdString();

    vector<string> commands(contents.size());
    for(int i = 0; i < contents.size(); i++)
    {
        commands[i] = contents[i].QString::toStdString();
    }
    Save *temp = new Save(name, commands, directory);
    delete temp;
}
