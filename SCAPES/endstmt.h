#ifndef ENDSTMT_H
#define ENDSTMT_H
#include "statement.h"

class EndStmt : public Statement
{
public:
    EndStmt();
    EndStmt(vector<string> lineParses);
    EndStmt(vector<string> lineParses, string label);
    void compile();
    void run();
};

#endif // ENDSTMT_H
