#ifndef EXECUTECONTROL_H
#define EXECUTECONTROL_H

#include <string>
#include "program.h"
using namespace std;
class executeControl
{
public:
    executeControl(string file, string dir);
    string executeProgram();
    int readInput();
    int output(string value);
private:
    string directory;
    string name;
    Program* program;
};

#endif // EXECUTECONTROL_H
