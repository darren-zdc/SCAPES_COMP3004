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
        logger->error("Invalid cmp input");
        return ERROR;
    }
    operands.push_back(Operand(p_operands[0]));
    operands.push_back(Operand(p_operands[1]));
    return SUCCESS;
}

int CompStmt::run()
{
    int var1 = program->getValueByInput(operands[0].getValue());
    int var2 = program->getValueByInput(operands[1].getValue());
    if (var1 < 0 || var2 < 0)
    {
        return ERROR;
    }
    if (var1 < var2)
    {
        program->setComparisonFlag(SMALLER);
    }
    else if (var1 > var2)
    {
        program->setComparisonFlag(GREATER);
    }
    else if(var1 == var2)
    {
        program->setComparisonFlag(EQUAL);
    }
    return 0;
}
