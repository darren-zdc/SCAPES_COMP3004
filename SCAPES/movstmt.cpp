#include "movstmt.h"
#include "program.h"
MovStmt::MovStmt()
{

}
MovStmt::MovStmt(vector<string> lineParses): Statement(lineParses)
{}

MovStmt::MovStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

MovStmt::MovStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

//Syntax checking
int MovStmt::compile()
{
    if(p_operands.size() != 2)
    {
        //error invalid input
        return ERROR;
    }

    operands.push_back(p_operands[0]);
    operands.push_back(p_operands[1]);
    return SUCCESS;
}

int MovStmt::run()
{
    return 0;
}
