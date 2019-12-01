#ifndef RENAMECONTROL_H
#define RENAMECONTROL_H

#include <string>

using namespace std;

class renameControl
{
public:
    renameControl(string filename, string newName, string dir);
    int renameFile();
private:
    string old;
    string name;
    string directory;
};

#endif // RENAMECONTROL_H
