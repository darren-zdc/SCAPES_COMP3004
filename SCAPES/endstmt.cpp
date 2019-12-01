#include "endstmt.h"

EndStmt::EndStmt()
{
}

EndStmt::EndStmt(vector<string> lineParses):Statement(lineParses)
{}

EndStmt::EndStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

EndStmt::EndStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

void EndStmt::run()
{

}

int EndStmt::compile()
{
    if(p_operands.size() != 0)
    {
        //error invalid input
        return 0;
    }
    return 1;
}
