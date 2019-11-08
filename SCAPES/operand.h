#ifndef OPERAND_H
#define OPERAND_H
#include "identifier.h"

class Operand
{
public:
    Operand();
    Operand(string name);
    Identifier identifier;
    string getValue();
};

#endif // OPERAND_H
