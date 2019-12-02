#include "addstmt.h"
#include "program.h"
AddStmt::AddStmt()
{

}
AddStmt::AddStmt(vector<string> lineParses): Statement(lineParses)
{}

AddStmt::AddStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

AddStmt::AddStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

//Syntax checking
int AddStmt::compile()
{
    if(p_operands.size() != 2)
    {
        //error invalid input
        return 0;
    }

    operands.push_back(p_operands[0]);
    operands.push_back(p_operands[1]);
    return 1;
}

int AddStmt::run()
{
    return 0;
}
