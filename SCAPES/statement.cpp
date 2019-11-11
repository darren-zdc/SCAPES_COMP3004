#include "program.h"
#include "statement.h"

Statement::~Statement()
{


}

Statement::Statement() {}

Statement::Statement(vector<string> lineParses): lineParses(lineParses), instruction(lineParses[0])
{}

string Statement::getInstruction()
{
    return instruction;
}

vector<Operand> Statement::getOperands()
{
    return operands;
}

void Statement::setProgram(Program &prog)
{
    program = &prog;
}
