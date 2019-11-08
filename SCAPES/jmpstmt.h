#ifndef JMPSTMT_H
#define JMPSTMT_H
#include "statement.h"

class JmpStmt : public Statement
{
public:
    JmpStmt();
    JmpStmt(string line);
    void compile();
    void run();
};

#endif // JMPSTMT_H
