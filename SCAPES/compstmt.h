#ifndef COMPSTMT_H
#define COMPSTMT_H
#include "statement.h"


class CompStmt: public Statement
{
public:
    CompStmt();
    CompStmt(vector<string> lineParses);
    CompStmt(vector<string> lineParses, string label);
    int compile();
    void run();
};

#endif // COMPSTMT_H
