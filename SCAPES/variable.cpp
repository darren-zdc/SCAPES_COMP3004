#include "variable.h"

Variable::Variable()
{

}

Variable::Variable(string name): Identifier (name)
{
    this->isArray = false;
    this->size = 0;
}

Variable::Variable(string name, int size): Identifier (name), size(size)
{
    this->isArray = true;
    this->size = size;
    this->arrayValues[static_cast<size_t>(size)];
}

int Variable::getValue()
{
    return value;
}

int Variable::getValueByIndex(int i)
{
    return arrayValues[static_cast<size_t>(i)];
}

void Variable::setValue(int value)
{
    this->value = value;
}

void Variable::setValueByIndex(int value, int i)
{
    this->arrayValues[static_cast<size_t>(i)] = value;
}

bool Variable::isVarArray(){
    return this->isArray;
}

int Variable::getSize(){
    return this->size;
}
