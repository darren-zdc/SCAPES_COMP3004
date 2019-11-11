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
void JmpStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
        return;
    }

    //check if the previous instruction is comp
    program->createLabel(lineParses[1]);
    operands.push_back(lineParses[1]);
}
