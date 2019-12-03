#include "printstmt.h"
#include "program.h"

PrintStmt::PrintStmt()
{

}

PrintStmt::PrintStmt(vector<string> lineParses) : Statement (lineParses)
{}

PrintStmt::PrintStmt(vector<string> lineParses, string label) : Statement (lineParses, label)
{}

PrintStmt::PrintStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

//Syntax checking
int PrintStmt::compile()
{
    // if its a string, it mustn't have space in the string
    // can improve later
    if(p_operands.size() != 1)
    {
        //error invalid input
        logger->error("Invalid prt input");
        return ERROR;
    }
    operands.push_back(Operand(p_operands[0]));
    return SUCCESS;
}

int PrintStmt::run()
{
    int value = program->getValueByInput(p_operands[0]);
    logger->error("printing: ");
    return 0;
}
