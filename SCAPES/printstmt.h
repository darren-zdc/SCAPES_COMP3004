#ifndef PRINTSTMT_H
#define PRINTSTMT_H
#include "statement.h"

class PrintStmt : public Statement
{
public:
    PrintStmt();
    PrintStmt(vector<string> lineParses);
    PrintStmt(vector<string> lineParses, string label);
    int compile();
    int run();
};

#endif // PRINTSTMT_H
