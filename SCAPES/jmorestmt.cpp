#include "jmorestmt.h"
#include "program.h"
JMoreStmt::JMoreStmt()
{

}
JMoreStmt::JMoreStmt(vector<string> lineParses): Statement(lineParses)
{}

JMoreStmt::JMoreStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

void JMoreStmt::run()
{

}

//Syntax checking
int JMoreStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
        return 0;
    }
    if (!program->ifPrevCompExist())
    {
        //error: previous instruction need to be comp
        return 0;
    }
    program->createLabel(lineParses[1]);
    operands.push_back(lineParses[1]);
    return 1;
}
