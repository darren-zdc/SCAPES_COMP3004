#include "endstmt.h"
#include "program.h"
EndStmt::EndStmt()
{
}

EndStmt::EndStmt(vector<string> lineParses):Statement(lineParses)
{}

EndStmt::EndStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

EndStmt::EndStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

int EndStmt::compile()
{
    if(p_operands.size() != 0)
    {
        //error invalid input
        logger->error("Invalid end input");
        return ERROR;
    }
    return SUCCESS;
}

int EndStmt::run()
{
    return END;
}
