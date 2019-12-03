#include "jlessstmt.h"
#include "program.h"
JLessStmt::JLessStmt()
{

}
JLessStmt::JLessStmt(vector<string> lineParses): Statement(lineParses)
{}

JLessStmt::JLessStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

JLessStmt::JLessStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

int JLessStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
        logger->error("Invalid jls input");
        return ERROR;
    }
    if (!program->ifPrevCompExist())
    {
        //error: previous instruction need to be comp
        logger->error("Previous statement is not cmp");
        return ERROR;
    }
    program->createLabel(p_operands[0]);
    operands.push_back(p_operands[0]);
    return 1;
}

int JLessStmt::run()
{
    if (program->getComparisonFlag() == SMALLER)
    {
        program->setJump(true);
    }
    return SUCCESS;
}
