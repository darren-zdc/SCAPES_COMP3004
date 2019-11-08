#ifndef JMORESTMT_H
#define JMORESTMT_H
#include "statement.h"

class JMoreStmt : public Statement
{
public:
    JMoreStmt();
    JMoreStmt(vector<string> lineParses);
    void compile();
    void run();
};

#endif // JMORESTMT_H
