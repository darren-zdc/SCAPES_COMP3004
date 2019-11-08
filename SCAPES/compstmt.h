#ifndef COMPSTMT_H
#define COMPSTMT_H
#include "statement.h"


class CompStmt: public Statement
{
public:
    CompStmt();
    CompStmt(string line);
    void compile();
    void run();
};

#endif // COMPSTMT_H
