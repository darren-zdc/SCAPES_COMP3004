#ifndef SYNTAXHELPER_H
#define SYNTAXHELPER_H

#include <string>
using namespace std;

class SyntaxHelper
{
public:
    SyntaxHelper();
    static int isInteger(string input);
    static int isArraySyntax(string input);

};

#endif // SYNTAXHELPER_H
