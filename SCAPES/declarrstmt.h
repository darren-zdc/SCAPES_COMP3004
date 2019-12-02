#ifndef DECLARRSTMT_H
#define DECLARRSTMT_H
#include "statement.h"

using namespace std;

class DeclArrStmt : public Statement
{
public:
    DeclArrStmt();
    DeclArrStmt(vector<string> line);
    DeclArrStmt(vector<string> line, string label);
    DeclArrStmt(string instr, vector<string> operds, string label);
    int compile();
    int run();
};
#endif // DECLARRSTMT_H
