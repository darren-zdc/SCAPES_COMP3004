#include "readstmt.h"
#include "program.h"
ReadStmt::ReadStmt()
{

}
ReadStmt::ReadStmt(vector<string> lineParses): Statement(lineParses)
{}

ReadStmt::ReadStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

ReadStmt::ReadStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

void ReadStmt::run()
{

}

//Syntax checking
int ReadStmt::compile()
{
    if (p_operands.size() != 1)
    {
        //error not a valid input
        return 0;
    }
    /*
    vector<Variable> temp;
    temp = program->getVariables();
    if(!program->ifExistVariable(lineParses[1]))
    {
        //error cannot find the variable inside the program variable
        return 0;
    }
    */
    operands.push_back(Operand(p_operands[0]));
    return 1;
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
