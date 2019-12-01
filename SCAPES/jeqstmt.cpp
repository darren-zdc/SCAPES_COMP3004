#include "jeqstmt.h"
#include "program.h"
JEqStmt::JEqStmt()
{

}
JEqStmt::JEqStmt(vector<string> lineParses): Statement(lineParses)
{}

JEqStmt::JEqStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

void JEqStmt::run()
{

}

//Syntax checking
int JEqStmt::compile()
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
