#ifndef READSTMT_H
#define READSTMT_H
#include "statement.h"
#include <type_traits>

class ReadStmt : public Statement
{
public:
    ReadStmt();
    ReadStmt(vector<string> lineParses);
    void compile();
    void run();
private:
    bool isNumber(string s);
};

#endif // READSTMT_H
