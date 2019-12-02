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
        return ERROR;
    }
    operands.push_back(Operand(p_operands[0]));
    operands.push_back(Operand(p_operands[1]));
    return SUCCESS;
}

int CompStmt::run()
{
    return 0;
}
