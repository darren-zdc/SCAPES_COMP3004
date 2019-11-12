#include "endstmt.h"

EndStmt::EndStmt()
{
}

EndStmt::EndStmt(vector<string> lineParses):Statement(lineParses)
{}

EndStmt::EndStmt(vector<string> lineParses, string label):Statement(lineParses, label)
{}

void EndStmt::run()
{

}

int EndStmt::compile()
{
    if(lineParses.size() != 1)
    {
        //error invalid input
        return 0;
    }
    return 1;
}
