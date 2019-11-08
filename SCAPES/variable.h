#ifndef VARIABLE_H
#define VARIABLE_H
#include "identifier.h"

class Variable : public Identifier
{
public:
    Variable();
    int getValue();
    void setValue(int value);
private:
    int value;
};

#endif // VARIABLE_H
