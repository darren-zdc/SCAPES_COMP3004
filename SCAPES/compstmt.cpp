#include "compstmt.h"
#include "program.h"
CompStmt::CompStmt()
{

}

CompStmt::CompStmt(vector<string> lineParses): Statement(lineParses)
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
    if(find(temp.begin(), temp.end(), lineParses[1]) == temp.end() || find(temp.begin(), temp.end(), lineParses[2]) == temp.end())
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
