#ifndef PRINTSTMT_H
#define PRINTSTMT_H
#include "statement.h"

class PrintStmt : public Statement
{
public:
    PrintStmt();
    PrintStmt(string line);
    void compile();
    void run();
};

#endif // PRINTSTMT_H
