#include "operand.h"

Operand::Operand()
{

}

Operand::Operand(string name) :identifier(Identifier(name))
{}


string Operand::getValue()
{
    return identifier.getName();
}

