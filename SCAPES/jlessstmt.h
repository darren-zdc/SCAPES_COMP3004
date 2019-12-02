#ifndef JLESSSTMT_H
#define JLESSSTMT_H
#include "statement.h"

class JLessStmt : public Statement
{
public:
    JLessStmt();
    JLessStmt(vector<string> lineParses);
    JLessStmt(vector<string> lineParses, string label);
    JLessStmt(string instr, vector<string> operds, string label);
    int compile();
    int run();
};

#endif // JLESSSTMT_H
