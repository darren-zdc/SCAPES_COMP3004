#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include <algorithm>
#include "operand.h"
#include "label.h"
#include "Logger.h"
using namespace  std;

class Program;

class Statement
{
public:
    Statement();
    Statement(vector<string> lineParses);
    Statement(vector<string> lineParses, string label);
    virtual ~Statement() = 0;
    virtual void compile() = 0;
    virtual void run() = 0;
    string getInstruction();
    vector<Operand> getOperands();
    Label* getLabel();
    void setProgram(Program &prog);
protected:
    vector<string> lineParses;
    vector<Operand> operands;
    Label label;
    string instruction;
    Program* program;
    CPlusPlusLogging::Logger* logger;

};
#endif // STATEMENT_H
