#include "program.h"
#include "statement.h"

Statement::~Statement()
{


}

Statement::Statement() {}

Statement::Statement(vector<string> lineParses): lineParses(lineParses), instruction(lineParses[0])
{}

Statement::Statement(vector<string> lineParses, string label): lineParses(lineParses), instruction(lineParses[0]), label(Label(label))
{
    //logger = nullptr;
    //logger = CPlusPlusLogging::Logger::getInstance();
}

Statement::Statement(string inst, vector<string> operds, string label) : p_operands(operds), instruction(inst), label(label)
{
    logger = Logger::getInstance();
}

string Statement::getInstruction()
{
    return instruction;
}

vector<Operand> Statement::getOperands()
{
    return operands;
}

Label* Statement::getLabel()
{
    return &label;
}

void Statement::setProgram(Program &prog)
{
    program = &prog;
}
