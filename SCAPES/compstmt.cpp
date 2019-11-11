#include "compstmt.h"
#include "program.h"
CompStmt::CompStmt()
{

}

CompStmt::CompStmt(vector<string> lineParses): Statement(lineParses)
{}

CompStmt::CompStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

//Syntax checking
void CompStmt::compile()
{
    if(lineParses.size() != 3)
    {
        //error invalid input
        return;
    }
    vector<Variable> temp = program->getVariables();
    if(!program->ifExistVariable(lineParses[1]) || !program->ifExistVariable(lineParses[2]))
    {
        //error cannot find the variable inside the program variable
        return;
    }
    operands.push_back(Operand(lineParses[1]));
    operands.push_back(Operand(lineParses[2]));
}

void CompStmt::run()
{

}
