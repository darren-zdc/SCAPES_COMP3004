#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include <algorithm>
#include "operand.h"
#include "label.h"
#include "logger.h"
using namespace  std;

class Program;

class Statement
{
public:
    Statement();
    Statement(vector<string> lineParses);
    Statement(vector<string> lineParses, string label);
    Statement(string instr, vector<string> operds, string label);

    virtual ~Statement() = 0;
    virtual int compile() = 0;
    virtual int run() = 0;
    string getInstruction();
    vector<Operand> getOperands();
    void setOperands(vector<string> operds);
    Label* getLabel();
    void setProgram(Program &prog);
protected:
    vector<string> lineParses;
    vector<string> p_operands;
    vector<Operand> operands;
    Label label;
    string instruction;
    Program* program;
    Logger* logger;
};
#endif // STATEMENT_H
