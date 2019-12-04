#include "jmorestmt.h"
#include "program.h"
JMoreStmt::JMoreStmt()
{

}
JMoreStmt::JMoreStmt(vector<string> lineParses): Statement(lineParses)
{}

JMoreStmt::JMoreStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

JMoreStmt::JMoreStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

//Syntax checking
int JMoreStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
        logger->error("Invalid jmr input");
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

int JMoreStmt::run()
{
    if (program->getComparisonFlag() == GREATER)
    {
        program->setJump(true);
    }
    return SUCCESS;
}
