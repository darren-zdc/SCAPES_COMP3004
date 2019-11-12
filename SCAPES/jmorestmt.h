#ifndef JMORESTMT_H
#define JMORESTMT_H
#include "statement.h"

class JMoreStmt : public Statement
{
public:
    JMoreStmt();
    JMoreStmt(vector<string> lineParses);
    JMoreStmt(vector<string> lineParses, string label);
    int compile();
    void run();
};

#endif // JMORESTMT_H
