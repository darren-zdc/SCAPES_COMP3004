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

    operands.push_back(p_operands[0]);
    operands.push_back(p_operands[1]);
    return SUCCESS;
}

int AddStmt::run()
{
    string destName;
    int sourceValue;
    int destValue;
    int destIndex;
    Variable *destVar;


    if(program->getValueByInput(p_operands[0]) != -1){
        sourceValue = program->getValueByInput(p_operands[0]);
    }else{
        return -1;
    }

    if(HelperFunction::isArraySyntax(p_operands[1],destName,&destIndex)){
        if(program->findVariable(destName, destVar)){
            if(destIndex > destVar->getSize() || destIndex < 1){
                destValue = destVar->getValueByIndex(destIndex);
            }else{
                logger->error("Array out of bound.");
                return -1;
            }
        }else{
            logger->error("Variable '" + destName + "' does not exist.");
            return -1;
        }
    }else{
        if(program->findVariable(destName, destVar)){
            destValue = destVar->getValue();
        }else{
            logger->error("Variable '" + destName + "' does not exist.");
            return -1;
        }
    }

    destVar->setValue(sourceValue+destValue);
    return 0;
}
