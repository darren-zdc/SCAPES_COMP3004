#include "readstmt.h"
#include "program.h"
#include "syntaxhelper.h"
ReadStmt::ReadStmt()
{

}
ReadStmt::ReadStmt(vector<string> lineParses): Statement(lineParses)
{}

ReadStmt::ReadStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

ReadStmt::ReadStmt(string instr, vector<string> operds, string label): Statement (instr, operds, label)
{}

//Syntax checking
int ReadStmt::compile()
{
    if (p_operands.size() != 1)
    {
        //error not a valid input
        return 0;
    }
    string varName = p_operands[0];
    if (varName[0] == '$')
    {
        if (!varName.find("+"))
            return ERROR;
        int index = stoi(varName.substr(varName.find("+"), varName.length() - varName.find("+")));
        if (index < 0)
        {
            //array index cannot less than 0
            return ERROR;
        }
    }
    else if (SyntaxHelper::isInteger(p_operands[0]))
    {
        //input is an integer
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
    operands.push_back(Operand(p_operands[0]));
    return SUCCESS;
}

int ReadStmt::run()
{
    string varName = operands[0].getValue();
    int index = 0;
    if (varName[0] == '$')
    {
        if (!varName.find("+"))
        {
            //Error: Syntax not right
            return ERROR;
        }
        index = stoi(varName.substr(varName.find("+"), varName.length() - varName.find("+")));
        varName = varName.substr(1, varName.find("+")-1);
    }
    Variable* output;
    if (!program->ifExistVariable(operands[0].getValue(), output))
    {
        //Error: variable not exists
        return ERROR;
    }
    int varValue = program->readInput();
    program->setVariable(varName, varValue, index);
    return SUCCESS;
}
