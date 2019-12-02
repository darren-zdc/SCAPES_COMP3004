#include "compstmt.h"
#include "program.h"
CompStmt::CompStmt()
{

}

CompStmt::CompStmt(vector<string> lineParses): Statement(lineParses)
{}

CompStmt::CompStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

CompStmt::CompStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}


//Syntax checking
int CompStmt::compile()
{
    if(p_operands.size() != 2)
    {
        //error invalid input
        //logger->error("Invalid input");
        return 0;
    }
    /*
    vector<Variable> temp = program->getVariables();
    if(!program->ifExistVariable(lineParses[1]) || !program->ifExistVariable(lineParses[2]))
    {
        //error cannot find the variable inside the program variable
        //logger->error("Duplicated variable declared");
        return 0;
    }
    */
    operands.push_back(Operand(p_operands[0]));
    operands.push_back(Operand(p_operands[1]));
    return 1;
}

int CompStmt::run()
{

}
