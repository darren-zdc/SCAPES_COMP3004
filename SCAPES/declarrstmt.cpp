#include "declarrstmt.h"
#include "program.h"
#include "helperfunction.h"

DeclArrStmt::DeclArrStmt()
{

}

DeclArrStmt::DeclArrStmt(vector<string> lineParses): Statement(lineParses)
{}

DeclArrStmt::DeclArrStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

DeclArrStmt::DeclArrStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

int DeclArrStmt::compile()
{
    if(p_operands.size() != 2)
    {
        //error invalid input
        logger->error("Invalid dca input");
        return ERROR;
    }

    if(!program->createVariable(p_operands[0]))
    {
        //error: variable already exists
        logger->error("Variable already exists");
        return ERROR;
    }
    return SUCCESS;
}

int DeclArrStmt::run()
{
    int arraySize = 0;
    if (program->findVariable(p_operands[0], nullptr))
    {
        logger->error("Variable already exist \'" + p_operands[0] + "\'");
        return ERROR;
    }
    if (HelperFunction::isNumber(operands[1].getValue()))
    {
        arraySize = stoi(operands[1].getValue());
    }
    else
    {
        arraySize = program->getValueByInput(operands[1].getValue());
        if (arraySize < 0)
        {
            logger->error("Invalid variable " + operands[1].getValue());
            return ERROR;
        }
    }
    program->createVariable(p_operands[0], arraySize);
    return SUCCESS;
}



