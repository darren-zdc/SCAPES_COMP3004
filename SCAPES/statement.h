#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include "operand.h"
#include "label.h"
using namespace  std;

class Program;

class Statement
{
public:
    Statement();
    Statement(vector<string> lineParses);
    virtual ~Statement() = 0;
    virtual void compile() = 0;
    virtual void run() = 0;
    string getInstruction();
    vector<Operand> getOperands();
    void setProgram(Program &prog);
protected:
    vector<string> lineParses;
    vector<Operand> operands;
    Label label;
    string instruction;
    Program* program;

};
#endif // STATEMENT_H
