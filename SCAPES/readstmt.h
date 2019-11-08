#ifndef READSTMT_H
#define READSTMT_H
#include "statement.h"

class ReadStmt : public Statement
{
public:
    ReadStmt();
    ReadStmt(string line);
    void compile();
    void run();
};

#endif // READSTMT_H
