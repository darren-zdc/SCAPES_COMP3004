#include "declintstmt.h"
#include "program.h"

DeclIntStmt::DeclIntStmt()
{

}

DeclIntStmt::DeclIntStmt(vector<string> lineParses): Statement(lineParses)
{}

DeclIntStmt::DeclIntStmt(vector<string> lineParses, string label): Statement(lineParses, label)
{}

void DeclIntStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
    }
    if(program->createVariable(lineParses[1]) != 1)
    {
        //error: variable already exists
        return;
    }
    operands.push_back(Operand(lineParses[1]));
}

void DeclIntStmt::run()
{


}
