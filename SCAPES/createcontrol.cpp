#include "createcontrol.h"
#include "Create.h"

createControl::createControl(string dir)
{
    this->directory = dir;
}

void createControl::createfile() //create new blank file in working directory
{
    Create *temp = new Create(directory);
    delete temp;
}
