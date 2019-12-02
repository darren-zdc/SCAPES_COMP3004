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
    int compile();
    void run();
};
#endif // DECLARRSTMT_H
