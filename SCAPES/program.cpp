#include "program.h"

Program::Program(string filename) : preference(), filename(filename)
{
}

void Program::Compile()
{
    string filePath = preference.getDirectory() + "/" + filename;
    list<string> lines;
    string line;
    ifstream myprogram(filePath);
    if (myprogram.is_open())
    {
        while(getline(myprogram, line))
        {
            createStatement(line);
            Statement* st = statements.back();
            st->compile();
            createIdentifier(st, line);
        }
    }

}

void Program::Execute()
{


}

void Program::createStatement(string line)
{
    vector<string> lineParses =split(line);
    if (lineParses[0] == "dci")
    {
        //declares an integer variable
        statements.push_back(new DeclIntStmt(lineParses));
    }
    else if (lineParses[0] == "rdi")
    {
        //reads an integer value from the user
        statements.push_back(new ReadStmt(lineParses));

    }
    else if (lineParses[0] == "prt")
    {
        //prints out the value of a variable
        statements.push_back(new PrintStmt(lineParses));
    }
    else if (lineParses[0] == "cmp")
    {
        //compares two values to test
        statements.push_back(new CompStmt(lineParses));

    }
    else if (lineParses[0] == "jmr")
    {
        //jump to the specified label
        statements.push_back(new JMoreStmt(lineParses));
    }
    else if (lineParses[0] == "jmp")
    {
        //unconditional jump to the specified labl
        statements.push_back(new JmpStmt(lineParses));
    }
    else if (lineParses[0] == "end")
    {
        //indicates the end of the program
        statements.push_back(new EndStmt());

        //Deconstruct the statement vector
    }
    else if (lineParses[0] == "#")
    {
        //indicates that the line is a comment
    }
    else
    {
        //error
    }
}

void Program::createIdentifier(Statement* st, string line)
{
    vector<string> lineParses =split(line);
    if (lineParses[0] == "dci")
    {
        //declares an integer variable
        identifiers.push_back(Identifier(lineParses[1]));
    }
    else if (lineParses[0] == "rdi")
    {
        //reads an integer value from the user

    }
    else if (lineParses[0] == "prt")
    {
        //prints out the value of a variable
    }
    else if (lineParses[0] == "cmp")
    {
        //compares two values to test

    }
    else if (lineParses[0] == "jmr")
    {
        //jump to the specified label

    }
    else if (lineParses[0] == "jmp")
    {
        //unconditional jump to the specified labl

    }
    else if (lineParses[0] == "#")
    {
        //indicates that the line is a comment
    }
    else
    {
        //error
    }
}


vector<string> Program::split(string line)
{
    istringstream iss(line);
    vector<string> results((istream_iterator<std::string>(iss)),
                   istream_iterator<std::string>());
    return results;
}
