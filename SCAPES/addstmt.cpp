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
        logger->error("Invalid add input");
        return ERROR;
    }
    return SUCCESS;
}

int AddStmt::run()
{
    string destName;
    int sourceValue;
    int destValue;
    string destIndex;
    int destI = 0;
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
            if (HelperFunction::isNumber(destIndex))
            {
                destI = stoi(destIndex);
            }
            else
            {
                Variable* indexVar;
                if (program->findVariable(destIndex, &indexVar))
                {
                    destI = indexVar->getValue();
                }
                else
                {
                    logger->error("Index variable \'"+ destIndex + "\' not exist");
                    return ERROR;
                }
            }
            if (destI > destVar->getSize() || destI < 0)
            {
                logger->error("Array out of bound.");
                return ERROR;
            }
            else
            {
                destValue = destVar->getValueByIndex(destI);
            }
        }
        else
        {
            logger->error("Variable '" + destName + "' does not exist.");
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
            logger->error("Variable \"" + destName + "\" does not exist.");
            return ERROR;
        }
    }

    program->setVariable(destName, sourceValue+destValue, destI);
    return SUCCESS;
}
