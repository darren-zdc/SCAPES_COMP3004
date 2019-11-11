#include "variable.h"

Variable::Variable()
{

}

Variable::Variable(string name): Identifier (name)
{}

Variable::Variable(string name, int value): Identifier (name), value(value)
{}

int Variable::getValue()
{
    return value;
}

void Variable::setValue(int value)
{
    this->value = value;
}
