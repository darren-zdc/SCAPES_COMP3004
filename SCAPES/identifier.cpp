#include "identifier.h"

Identifier::Identifier()
{

}

Identifier::Identifier(string name): name(name)
{}

string Identifier::getName()
{
    return name;
}
