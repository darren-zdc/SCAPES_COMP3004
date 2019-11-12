#include "printstmt.h"
#include "program.h"

PrintStmt::PrintStmt()
{

}

PrintStmt::PrintStmt(vector<string> lineParses) : Statement (lineParses)
{}

PrintStmt::PrintStmt(vector<string> lineParses, string label) : Statement (lineParses, label)
{}

void PrintStmt::run()
{

}

//Syntax checking
int PrintStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
    }
    vector<Variable> temp;
    temp = program->getVariables();
    if(!program->ifExistVariable(lineParses[1]))
    {
        //error cannot find the variable inside the program variable
        return 0;
    }
    operands.push_back(Operand(lineParses[1]));
    return 1;
}
