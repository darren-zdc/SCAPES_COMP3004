#include "readstmt.h"

ReadStmt::ReadStmt()
{

}
ReadStmt::ReadStmt(vector<string> lineParses): Statement(lineParses)
{}

void ReadStmt::run()
{

}

//Syntax checking
void ReadStmt::compile()
{
    if (lineParses.size() != 2)
    {
        //error not a valid input
    }
    if (!isNumber(lineParses[1]))
    {
        //error not a integer
    }
    operands.push_back(Operand(lineParses[1]));
}


bool ReadStmt::isNumber(string s)
{
    for (int i=0; i< s.length(); i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}
