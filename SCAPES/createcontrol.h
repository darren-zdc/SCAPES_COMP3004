#ifndef CREATECONTROL_H
#define CREATECONTROL_H

#include <string>
using namespace std;

class createControl
{
public:
    createControl(string dir);
    void createfile();
private:
    string directory;
};

#endif // CREATECONTROL_H
