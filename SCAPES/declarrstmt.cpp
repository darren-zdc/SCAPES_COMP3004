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

    // check if its a number
    // max array length can not be less than 0
    if(HelperFunction::isNumber(p_operands[1]))
    {
        if(std::stoi(p_operands[1]) < 0)
        {
            //error: invalid index < 0
            logger->error("Invalid index size <0");
            return ERROR;
        }
    }
    else
    {
        //Error: not a number
        logger->error("Invalid array size");
        return ERROR;
    }

    if(!program->createVariable(lineParses[1], std::stoi(p_operands[1])))
    {
        //error: variable already exists
        logger->error("Variable already exists");
        return ERROR;
    }



    operands.push_back(Operand(p_operands[0]));
    operands.push_back(Operand(p_operands[1]));
    return SUCCESS;
}

int DeclArrStmt::run()
{

    return 0;
}



