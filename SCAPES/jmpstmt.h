#ifndef JMPSTMT_H
#define JMPSTMT_H
#include "statement.h"

class JmpStmt : public Statement
{
public:
    JmpStmt();
    JmpStmt(vector<string> lineParses);
    JmpStmt(vector<string> lineParses, string label);
    void compile();
    void run();
};

#endif // JMPSTMT_H
