#ifndef VARIABLE_H
#define VARIABLE_H
#include "identifier.h"

class Variable : public Identifier
{
public:
    Variable();
    Variable(string name);
    Variable(string name, int value);
    int getValue();
    void setValue(int value);
private:
    int value;
};

#endif // VARIABLE_H
