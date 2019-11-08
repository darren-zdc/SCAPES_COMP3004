#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <string>

using namespace std;

class Identifier
{
public:
    Identifier();
    Identifier(string name);
    string getName();
private:
    string name;
};

#endif // IDENTIFIER_H
