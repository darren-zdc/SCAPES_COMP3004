#ifndef JEQSTMT_H
#define JEQSTMT_H
#include "statement.h"

class JEqStmt : public Statement
{
public:
    JEqStmt();
    JEqStmt(vector<string> lineParses);
    JEqStmt(vector<string> lineParses, string label);
    int compile();
    void run();
};

#endif // JEQSTMT_H
