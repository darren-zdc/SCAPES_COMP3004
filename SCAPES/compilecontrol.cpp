#include "compilecontrol.h"
#include <program.h>

compileControl::compileControl(QString name, string dir)
{
    this->filename = name;
    this->directory = dir;
}

int compileControl::compile()
{
    Program *prog = new Program(filename.QString::toStdString(), directory);
    return prog->Compile();
}
