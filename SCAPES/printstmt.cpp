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
    return SUCCESS;
}

int PrintStmt::run()
{
    if (p_operands[0][0] == '"')
    {
        program->appendProgramOutput(p_operands[0]);
	logger->info("Printing: " + p_operands[0]);
        return SUCCESS;
    }
    int output = program->getValueByInput(p_operands[0]);
    if (output >= 0)
    {
        program->appendProgramOutput(to_string(output));
	logger->info("Printing: " + to_string(output));
        return SUCCESS;
    }
    else
    {	
        logger->error("Invalid print statement");
        return ERROR;
    }
    return 0;
}
