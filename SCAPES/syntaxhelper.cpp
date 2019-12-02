#include "syntaxhelper.h"

SyntaxHelper::SyntaxHelper()
{

}

int isInteger(string & input)
{
    string::const_iterator it = input.begin();
    while (it != input.end() && isdigit(*it)) ++it;
    return !input.empty() && it == input.end();
}

int isArraySyntax(string input)
{
    if (input[0] == '$')
    {
        if (!input.find("+"))
            return 0;
        int index = stoi(input.substr(input.find("+"), input.length() - input.find("+")));
        if (index < 0)
        {
            //array index cannot less than 0
            return 0;
        }
        return 1;
    }
    return 0;
}
