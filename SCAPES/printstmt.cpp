#include "printstmt.h"
#include "program.h"

PrintStmt::PrintStmt()
{

}

PrintStmt::PrintStmt(vector<string> lineParses) : Statement (lineParses)
{

}
void PrintStmt::run()
{

}

//Syntax checking
void PrintStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
    }
    vector<Variable> temp;
    temp = program->getVariables();
    if(find(temp.begin(), temp.end(), lineParses[1]) == temp.end())
    {
        //error cannot find the variable inside the program variable
        return;
    }
    operands.push_back(Operand(lineParses[1]));
}
