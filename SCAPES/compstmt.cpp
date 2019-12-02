#include "compstmt.h"
#include "program.h"
CompStmt::CompStmt()
{

}

CompStmt::CompStmt(vector<string> lineParses): Statement(lineParses)
{}

CompStmt::CompStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

//Syntax checking
int CompStmt::compile()
{
    if(lineParses.size() != 3)
    {
        //error invalid input
        //logger->error("Invalid input");
        return 0;
    }


    operands.push_back(Operand(lineParses[1]));
    operands.push_back(Operand(lineParses[2]));
    return 1;
}

int CompStmt::run()
{

}
