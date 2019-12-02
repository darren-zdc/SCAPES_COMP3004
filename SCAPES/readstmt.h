#ifndef READSTMT_H
#define READSTMT_H
#include "statement.h"
#include <type_traits>

class ReadStmt : public Statement
{
public:
    ReadStmt();
    ReadStmt(vector<string> lineParses);
    ReadStmt(vector<string> lineParses, string label);
    ReadStmt(string instr, vector<string> operds, string label);

    int compile();
    int run();
private:
    bool isNumber(string s);
};

#endif // READSTMT_H
