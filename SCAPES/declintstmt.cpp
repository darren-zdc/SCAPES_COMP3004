#include "declintstmt.h"
#include "program.h"

DeclIntStmt::DeclIntStmt()
{

}

DeclIntStmt::DeclIntStmt(vector<string> lineParses): Statement(lineParses)
{}

//Syntax checking
void DeclIntStmt::compile()
{
    if(lineParses.size() != 2)
    {
        //error invalid input
    }
    operands.push_back(Operand(lineParses[1]));
    //program->createVariable(lineParses[1]);
}

void DeclIntStmt::run()
{


}
