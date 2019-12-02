#ifndef JEQSTMT_H
#define JEQSTMT_H
#include "statement.h"

class JEqStmt : public Statement
{
public:
    JEqStmt();
    JEqStmt(vector<string> lineParses);
    JEqStmt(vector<string> lineParses, string label);
    JEqStmt(string instr, vector<string> operds, string label);
    int compile();
    int run();
};

#endif // JEQSTMT_H
