#ifndef VARIABLE_H
#define VARIABLE_H
#include "identifier.h"
#include <vector>

class Variable : public Identifier
{
public:
    Variable();
    Variable(string name);
    Variable(string name, int size);
    ~Variable();
    int getValue();
    int getValueByIndex(int i); // for array
    void setValue(int value);
    void setValueByIndex(int value, int i);
    bool isVarArray();
    int getSize();
private:
    int value;
    int size;
    bool isArray;
    int arrayValues[10];
};

#endif // VARIABLE_H
