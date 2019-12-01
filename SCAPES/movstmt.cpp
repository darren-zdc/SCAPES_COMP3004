#include "movstmt.h"
#include "program.h"
MovStmt::MovStmt()
{

}
MovStmt::MovStmt(vector<string> lineParses): Statement(lineParses)
{}

MovStmt::MovStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

void MovStmt::run()
{

}

//Syntax checking
int MovStmt::compile()
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
