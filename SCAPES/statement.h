#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
#include "operand.h"
#include "label.h"
using namespace  std;
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
protected:
    vector<string> lineParses;
    vector<Operand> operands;
    Label label;
    string instruction;

};
#endif // STATEMENT_H
