#ifndef MOVSTMT_H
#define MOVSTMT_H
#include "statement.h"

class MovStmt : public Statement
{
public:
    MovStmt();
    MovStmt(vector<string> lineParses);
    MovStmt(vector<string> lineParses, string label);
    int compile();
    void run();
};

#endif // MOVSTMT_H
