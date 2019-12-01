#include "jmpstmt.h"
#include "program.h"
JmpStmt::JmpStmt()
{

}

JmpStmt::JmpStmt(vector<string> lineParses): Statement (lineParses)
{}

JmpStmt::JmpStmt(vector<string> lineParses, string label): Statement (lineParses, label)
{}

JmpStmt::JmpStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

void JmpStmt::run()
{

}

//Syntax checking
int JmpStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
        return 0;
    }

    program->createLabel(p_operands[0]);
    operands.push_back(p_operands[0]);
    return 1;
}
