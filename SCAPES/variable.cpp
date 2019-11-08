#include "variable.h"

Variable::Variable()
{

}

int Variable::getValue()
{
    return value;
}

void Variable::setValue(int value)
{
    this->value = value;
}
