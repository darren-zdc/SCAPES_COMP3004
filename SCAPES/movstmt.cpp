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
        program->setVariable(destName, sourceValue, destI);
    return SUCCESS;
}
