#include "createcontrol.h"
#include "Create.h"

createControl::createControl(string dir)
{
    this->directory = dir;
}

void createControl::createfile()
{
    Create *temp = new Create(directory);
    delete temp;
}
