#include "declarrstmt.h"
#include "program.h"

DeclArrStmt::DeclArrStmt()
{

}

DeclArrStmt::DeclArrStmt(vector<string> lineParses): Statement(lineParses)
{}

DeclArrStmt::DeclArrStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{

}

int DeclArrStmt::compile()
{
    if(lineParses.size() != 3)
    {
        //error invalid input
        return 0;
    }

    // check if its a number
    // max array length can not be less than 0
    if(program->isNumber(lineParses[2])){
        if(std::stoi(lineParses[2]) <= 0){
            return 0;
        }
    }else{
        // is not a number
        return 0;
    }

    if(program->createVariable(lineParses[1], std::stoi(lineParses[2])) != 1)
    {
        //error: variable already exists
        return 0;
    }



    operands.push_back(Operand(lineParses[1]));
    operands.push_back(Operand(lineParses[2]));
    return 1;
}

void DeclArrStmt::run()
{


}



