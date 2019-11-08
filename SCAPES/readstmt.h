#ifndef READSTMT_H
#define READSTMT_H
#include "statement.h"

class ReadStmt : public Statement
{
public:
    ReadStmt();
    ReadStmt(vector<string> lineParses);
    void compile();
    void run();
};

#endif // READSTMT_H
