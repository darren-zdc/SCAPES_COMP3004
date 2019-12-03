#ifndef EXECUTECONTROL_H
#define EXECUTECONTROL_H

#include <string>
#include "program.h"
using namespace std;

class filemanager;

class executeControl
{
public:
    executeControl(string file, string dir, filemanager* manager);
    string executeProgram();
    int readInput(string name);
    int output(string value);
private:
    string directory;
    string name;
    Program* program;
    filemanager* manager;
};

#endif // EXECUTECONTROL_H
