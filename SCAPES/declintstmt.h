#ifndef DECLINTSTMT_H
#define DECLINTSTMT_H
#include "statement.h"
#include <string>

using namespace std;

class DeclIntStmt : public Statement
{
public:
    DeclIntStmt();
    DeclIntStmt(string line);
    void compile();
    void run();
};
#endif // DECLINTSTMT_H
