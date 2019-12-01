#include "jmpstmt.h"
#include "program.h"
JmpStmt::JmpStmt()
{

}

JmpStmt::JmpStmt(vector<string> lineParses): Statement (lineParses)
{}

JmpStmt::JmpStmt(vector<string> lineParses, string label): Statement (lineParses, label)
{}

void JmpStmt::run()
{

}

//Syntax checking
int JmpStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
        return 0;
    }

    //check if the previous instruction is comp
    program->createLabel(lineParses[1]);
    operands.push_back(lineParses[1]);
    return 1;
}
