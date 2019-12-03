#include "movstmt.h"
#include "program.h"
#include "helperfunction.h"
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
        logger->error("Invalid mov input");
        return ERROR;
    }
    return SUCCESS;
}

int MovStmt::run()
{
    string destName;
    int sourceValue;
    int destValue;
    int destIndex;
    Variable *destVar;


    if (program->getValueByInput(p_operands[0]) != -1)
    {
        sourceValue = program->getValueByInput(p_operands[0]);
    }
    else
    {
        return ERROR;
    }

    if (HelperFunction::isArraySyntax(p_operands[1],&destName,&destIndex))
    {
        if (program->findVariable(destName, &destVar))
        {
            if (destIndex > destVar->getSize() || destIndex < 1)
            {
                destValue = destVar->getValueByIndex(destIndex);
            }
            else
            {
                logger->error("Array out of bound.");
                return ERROR;
            }
        }
        else
        {
            logger->error("Variable \"" + destName + "\" does not exist");
            return ERROR;
        }
    }
    else
    {
        destName = p_operands[1];
        if (program->findVariable(destName, &destVar))
        {
            destValue = destVar->getValue();
        }
        else
        {
            logger->error("Variable '" + destName + "' does not exist.");
            return ERROR;
        }
    }

    destVar->setValue(sourceValue);
    return SUCCESS;
}
