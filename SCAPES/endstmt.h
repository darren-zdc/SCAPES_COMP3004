#ifndef ENDSTMT_H
#define ENDSTMT_H
#include "statement.h"

class EndStmt : public Statement
{
public:
    EndStmt();
    void compile();
    void run();
};

#endif // ENDSTMT_H
