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
    if(lineParses.size() != 2) // if its a string, it mustn't have space in the string
                                // can improve later
    {
        //error invalid input
        return 0;
    }
    vector<Variable> temp;
    temp = program->getVariables();
    operands.push_back(Operand(lineParses[1]));
    return 1;
}
