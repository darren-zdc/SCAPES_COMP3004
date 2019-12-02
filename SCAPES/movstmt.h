#ifndef MOVSTMT_H
#define MOVSTMT_H
#include "statement.h"

class MovStmt : public Statement
{
public:
    MovStmt();
    MovStmt(vector<string> lineParses);
    MovStmt(vector<string> lineParses, string label);
    MovStmt(string instr, vector<string> operds, string label);

    int compile();
    int run();
};

#endif // MOVSTMT_H
