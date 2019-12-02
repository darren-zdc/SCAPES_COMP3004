#include "addstmt.h"
#include "program.h"
AddStmt::AddStmt()
{

}
AddStmt::AddStmt(vector<string> lineParses): Statement(lineParses)
{}

AddStmt::AddStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

void AddStmt::run()
{

}

//Syntax checking
int AddStmt::compile()
{
    if(lineParses.size() != 3)
    {
        //error invalid input
        return 0;
    }




    operands.push_back(lineParses[1]);
    operands.push_back(lineParses[2]);
    return 1;
}
