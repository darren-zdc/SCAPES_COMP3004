#include "declintstmt.h"

DeclIntStmt::DeclIntStmt()
{

}

DeclIntStmt::DeclIntStmt(vector<string> lineParses): Statement(lineParses)
{}

//Syntax checking
void DeclIntStmt::compile()
{
    operands.push_back(Operand(lineParses[1]));
}

void DeclIntStmt::run()
{


}
