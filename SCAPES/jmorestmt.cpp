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

void JMoreStmt::run()
{

}

//Syntax checking
int JMoreStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
        return 0;
    }
    if (!program->ifPrevCompExist())
    {
        //error: previous instruction need to be comp
        return 0;
    }
    program->createLabel(p_operands[0]);
    operands.push_back(p_operands[0]);
    return 1;
}
