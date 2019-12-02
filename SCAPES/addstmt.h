#ifndef ADDSTMT_H
#define ADDSTMT_H
#include "statement.h"

class AddStmt : public Statement
{
public:
    AddStmt();
    AddStmt(vector<string> lineParses);
    AddStmt(vector<string> lineParses, string label);
    AddStmt(string instr, vector<string> operds, string label);
    int compile();
    int run();
};

#endif // ADDSTMT_H
