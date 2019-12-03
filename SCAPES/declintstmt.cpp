#include "declintstmt.h"
#include "program.h"

DeclIntStmt::DeclIntStmt()
{

}

DeclIntStmt::DeclIntStmt(vector<string> lineParses): Statement(lineParses)
{}

DeclIntStmt::DeclIntStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

DeclIntStmt::DeclIntStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

int DeclIntStmt::compile()
{
    if(p_operands.size() != 1)
    {
        //error invalid input
        logger->error("Invalid dci input");
        return ERROR;
    }
    if(program->createVariable(p_operands[0]) != 1)
    {
        //error: variable already exists
        logger->error("Variablie " + p_operands[0] + " already exists");
        return ERROR;
    }
    operands.push_back(Operand(p_operands[0]));
    return SUCCESS;
}

int DeclIntStmt::run()
{
    return SUCCESS;
}
