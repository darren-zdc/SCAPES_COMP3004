#ifndef LABEL_H
#define LABEL_H
#include "identifier.h"

class Label : public Identifier
{
public:
    Label();
    Label(string name);
};

#endif // LABEL_H
