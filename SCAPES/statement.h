#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
#include "label.h"
using namespace  std;
class Statement
{
public:
    Statement();
    Statement(string line);
    virtual ~Statement() = 0;
    virtual void compile() = 0;
    virtual void run() = 0;
protected:
    string line;
    Label label;

};
#endif // STATEMENT_H
