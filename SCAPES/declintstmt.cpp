#include "declintstmt.h"
#include "program.h"

DeclIntStmt::DeclIntStmt()
{

}

DeclIntStmt::DeclIntStmt(vector<string> lineParses): Statement(lineParses)
{}

DeclIntStmt::DeclIntStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{

}

int DeclIntStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
        return 0;
    }
    if(program->createVariable(lineParses[1], 0) != 1)
    {
        //error: variable already exists
        return 0;
    }
    operands.push_back(Operand(lineParses[1]));
    return 1;
}

void DeclIntStmt::run()
{


}
