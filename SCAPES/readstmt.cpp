#include "readstmt.h"
#include "program.h"
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
        return;
    }
    vector<Variable> temp;
    temp = program->getVariables();
    if(!program->ifExistVariable(Variable(lineParses[1])))
    {
        //error cannot find the variable inside the program variable
        return;
    }
    operands.push_back(Operand(lineParses[1]));
}

/*
bool ReadStmt::isNumber(string s)
{
    for (int i=0; i< s.length(); i++)
        if(!isdigit(s[i]))
            return false;
    return true;
}
*/
