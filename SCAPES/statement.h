#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include <vector>
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
protected:
    vector<string> lineParses;
    Label label;

};
#endif // STATEMENT_H
