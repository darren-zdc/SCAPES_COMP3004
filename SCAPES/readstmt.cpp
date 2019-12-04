#include "readstmt.h"
#include "program.h"
#include "helperfunction.h"
ReadStmt::ReadStmt()
{

}
ReadStmt::ReadStmt(vector<string> lineParses): Statement(lineParses)
{}

ReadStmt::ReadStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

ReadStmt::ReadStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

int ReadStmt::compile()
{
    if (p_operands.size() != 1)
    {
        //error not a valid input
        logger->error("Invalid rdi input");
        return 0;
    }
    string varName = p_operands[0];
    if (varName[0] == '$')
    {
        if (!varName.find("+"))
        {
            logger->error("Invalid array representation");
            return ERROR;
        }


        //int index = stoi(varName.substr(varName.find("+"), varName.length() - varName.find("+")));
        /*if (index < 0)
        {
            //array index cannot less than 0
            logger->error("Invalid array index");
            return ERROR;
        }*/
    }
    else if (HelperFunction::isNumber(p_operands[0]))
    {
        //input is an integer
        logger->error("Invalid variable");
        return ERROR;
    }
    /*
    vector<Variable> temp;
    temp = program->getVariables();
    if(!program->ifExistVariable(lineParses[1]))
    {
        //error cannot find the variable inside the program variable
        return 0;
    }
    */
    return SUCCESS;
}

int ReadStmt::run()
{
    string varName = p_operands[0];
    string index;
    int i = -1;
    if (HelperFunction::isArraySyntax(varName, &varName, &index))
    {
        if (HelperFunction::isNumber(index))
        {
            i = stoi(index);
        }
        //if the input the not a number
        else
        {
            Variable* indexVar;
            if (program->findVariable(index, &indexVar))
            {
                i = indexVar->getValue();
            }
            else
            {
                logger->error("Index variable not find");
                return -1;
            }
        }
    }

    if (!program->findVariable(varName, nullptr))
    {
        //Error: variable not exists
        logger->error("variable not found");
        return ERROR;
    }

    if(i >= 0){
        return program->setVariable(varName, program->readInput(varName + " at index " + std::to_string(i)), i);
    }else{
        return program->setVariable(varName, program->readInput(p_operands[0]), i);
    }
}
