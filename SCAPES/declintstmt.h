#ifndef DECLINTSTMT_H
#define DECLINTSTMT_H
#include "statement.h"

using namespace std;

class DeclIntStmt : public Statement
{
public:
    DeclIntStmt();
    DeclIntStmt(vector<string> line);
    DeclIntStmt(vector<string> line, string label);
    DeclIntStmt(string instr, vector<string> operds, string label);

    int compile();
    int run();
};
#endif // DECLINTSTMT_H
