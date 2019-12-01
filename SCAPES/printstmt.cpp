#include "printstmt.h"
#include "program.h"

PrintStmt::PrintStmt()
{

}

PrintStmt::PrintStmt(vector<string> lineParses) : Statement (lineParses)
{}

PrintStmt::PrintStmt(vector<string> lineParses, string label) : Statement (lineParses, label)
{}

PrintStmt::PrintStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

void PrintStmt::run()
{

}

//Syntax checking
int PrintStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
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
