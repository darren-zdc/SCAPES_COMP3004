#ifndef STATEMENT_H
#define STATEMENT_H
#include <string>
using namespace  std;
class Statement
{
public:
    Statement();
    void compile(string input);
    void run();
};
#endif // STATEMENT_H
