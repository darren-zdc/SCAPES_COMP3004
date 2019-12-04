#include "jeqstmt.h"
#include "program.h"
JEqStmt::JEqStmt()
{

}
JEqStmt::JEqStmt(vector<string> lineParses): Statement(lineParses)
{}

JEqStmt::JEqStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

JEqStmt::JEqStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

//Syntax checking
int JEqStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
        logger->error("Invalid jeq input");
        return ERROR;
    }
    if (!program->ifPrevCompExist())
    {
        //error: previous instruction need to be comp
        logger->error("Previous statement is not cmp");
        return ERROR;
    }
    program->createLabel(p_operands[0]);
    return SUCCESS;
}

int JEqStmt::run()
{
    if (program->getComparisonFlag() == EQUAL)
    {
        program->setJump(true);
    }
    return SUCCESS;
}
