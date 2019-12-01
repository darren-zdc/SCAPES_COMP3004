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
    int compile();
    void run();
};
#endif // DECLINTSTMT_H
