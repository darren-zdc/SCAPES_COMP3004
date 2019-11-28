#ifndef EXECUTECONTROL_H
#define EXECUTECONTROL_H

#include <string>

using namespace std;
class executeControl
{
public:
    executeControl(string file, string dir);
    string executeProgram();
private:
    string directory;
    string name;
};

#endif // EXECUTECONTROL_H
