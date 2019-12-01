#include "jlessstmt.h"
#include "program.h"
JLessStmt::JLessStmt()
{

}
JLessStmt::JLessStmt(vector<string> lineParses): Statement(lineParses)
{}

JLessStmt::JLessStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

void JLessStmt::run()
{

}

//Syntax checking
int JLessStmt::compile()
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
