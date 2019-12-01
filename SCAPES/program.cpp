#include "program.h"

enum flag{ERROR, SUCCESS, CONTINUE};

Program::Program(string filename, string dir) : filename(filename), directory(dir)
{

}

vector<Variable> Program::getVariables()
{
    return variables;
}

int Program::Compile()
{
    string filePath = directory + "/" + filename;
    list<string> lines;
    string line;
    ifstream myprogram(filePath);
    if (myprogram.is_open())
    {
        while(getline(myprogram, line))
        {
            int flag = createStatement(line);
            if (flag == SUCCESS)
            {
                Statement* st = statements.back();
                if(st->compile() == ERROR)
                {
                    return ERROR;
                }
            }
            else if (flag == ERROR)
            {
                return ERROR;
            }
        }
    }
    else if (myprogram.fail())
    {
        //failed to open a file
        return ERROR;
    }

    //Overall check
    for (Label l : labels)
    {
        bool isLabelDeclared = false;
        for (Statement* st : statements)
        {
            if (st->getLabel()->getName() == l.getName())
            {
               isLabelDeclared = true;
               break;
            }
        }
        if (isLabelDeclared == false)
        {
            //Label never declared
            return ERROR;
        }
    }


    //serialization to .cscapes
    this->serializeToJSON();
    return SUCCESS;
}

int Program::Execute()
{

    return 0;
}
int Program::createStatement(string instr, vector<string> operds, string label)
{
    if (instr == "dci")
    {
        //declares an integer variable
        statements.push_back(new DeclIntStmt(instr, operds, label));
    }
    else if (instr == "rdi")
    {
        //reads an integer value from the user
        statements.push_back(new ReadStmt(instr, operds, label));

    }
    else if (instr == "prt")
    {
        //prints out the value of a variable
        statements.push_back(new PrintStmt(instr, operds, label));
    }
    else if (instr == "cmp")
    {
        //compares two values to test
        statements.push_back(new CompStmt(instr, operds, label));

    }
    else if (instr == "jmr")
    {
        //jump to the specified label
        statements.push_back(new JMoreStmt(instr, operds, label));
    }
    else if (instr == "jmp")
    {
        //unconditional jump to the specified labl
        statements.push_back(new JmpStmt(instr, operds, label));
    }
    else if (instr == "end")
    {
        //indicates the end of the program
        statements.push_back(new EndStmt(instr, operds, label));
        //Deconstruct the statement vector
    }
    else
    {
        //error
        return ERROR;
    }
}

int Program::createStatement(string line, string label)
{
    vector<string> lineParses =split(line);

    //Case for empty line
    if (lineParses.size() == 0)
    {
        return CONTINUE;
    }
    else if (line[0] == '#')
    {
        //indicates that the line is a comment
        return CONTINUE;
    }
    else if (lineParses[0].back() == ':')
    {       
        this->createStatement(line.substr(lineParses[0].length()+1, line.length() - lineParses[0].length())
                , lineParses[0].substr(0,lineParses[0].size()-1));
        return SUCCESS;
    }
    else if (lineParses[0] == "\r" || lineParses[0] == "\n" || line == "")
    {
        return CONTINUE;
    }
    else
    {
        vector<string> tempOperds(lineParses.begin()+1, lineParses.end());
        createStatement(lineParses[0], tempOperds, label);
    }
    statements.back()->setProgram(*this);
    return SUCCESS;
}

int Program::createVariable(string name)
{
    if(ifExistVariable(name))
    {
        return 0;
    }
    variables.push_back(Variable(name));
    return 1;
}

void Program::createLabel(string name)
{
    if (!ifExistLabel(name))
    {
        labels.push_back(Label(name));
    }
}
void Program::serializeToJSON()
{
    QJsonObject jProgram;
    jProgram["filename"] = QString::fromStdString(this->filename);

    //serialize the statement vector
    QJsonArray jStatements;
    for (Statement* st :statements)
    {
        QJsonObject jStatement;
        jStatement["instruction"] = QString::fromStdString(st->getInstruction());
        QJsonArray jOperands;
        for (Operand op: st->getOperands())
        {
            QJsonObject jOperand;
            jOperand["name"] = QString::fromStdString(op.getValue());
            jOperands.push_back(jOperand);
        }
        if (jOperands.size() != 0)
        {
            jStatement["operands"] = jOperands;
        }
        if (st->getLabel()->getName() != "")
        {
            jStatement["label"] = QString::fromStdString(st->getLabel()->getName());
        }
        jStatements.push_back(jStatement);
    }
    jProgram["statements"] =jStatements;

    //serialize the variable vector
    QJsonArray jVariables;
    for(Variable var:variables)
    {
        QJsonObject jVariable;
        jVariable["name"] = QString::fromStdString(var.getName());
        jVariables.push_back(jVariable);
    }
    jProgram["variables"] = jVariables;

    //serialize the label vector
    QJsonArray jLabels;
    for(Label l:labels)
    {
        QJsonObject jLabel;
        jLabel["name"] = QString::fromStdString(l.getName());
        jLabels.push_back(jLabel);
    }
    jProgram["labels"] = jLabels;

    QJsonDocument doc(jProgram);
    string jsonFilename;
    jsonFilename = directory + "/" + getFileName("/" + this->filename, false) + ".json";
    QFile jsonFile(QString::fromStdString(jsonFilename));
    jsonFile.open(QIODevice::WriteOnly);
    jsonFile.write(doc.toJson());

}

Program* Program::deserializeToObject(string jsonFilename, string dir)
{
    QFile jsonFile(QString::fromStdString(dir + "/" + jsonFilename));
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString programJson = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument programDoc = QJsonDocument::fromJson(programJson.toUtf8());
    QJsonObject jProgram = programDoc.object();
    string filenameFromJson = jProgram["filename"].toString().toStdString();
    Program p(filenameFromJson, dir);
    QJsonArray sts = jProgram["statements"].toArray();
    foreach (const QJsonValue & st, sts)
    {
        QJsonObject jSt = st.toObject();

    }
}

vector<string> Program::split(string line)
{
    istringstream iss(line);
    vector<string> results((istream_iterator<std::string>(iss)),
                   istream_iterator<std::string>());
    return results;
}


string Program::getFileName(string filePath, bool withExtension, char seperator)
{
    // Get last dot position
    std::size_t dotPos = filePath.rfind('.');
    std::size_t sepPos = filePath.rfind(seperator);
    int extensionLength;
    extensionLength = filePath.size() - dotPos +1;
    if(sepPos != string::npos)
    {
        return filePath.substr(sepPos + 1, filePath.size() - (withExtension ? 1 : extensionLength) );
    }
    return "";
}
/*
Variable* Program::findVariable(Variable var)
{
    for(Variable element: variables)
    {
        if (element.getName() == var.getName())
            return &element;
    }
    return nullptr;
}
*/
int Program::ifExistVariable(string name)
{
    for(Variable element: variables)
    {
        if (element.getName() == name)
            return 1;
    }
    return 0;
}

int Program::ifExistLabel(string name)
{
    for(Label element: labels)
    {
        if (element.getName() == name)
            return 1;
    }
    return 0;
}

int Program::ifPrevCompExist()
{
    if(statements.rbegin()[1]->getInstruction() == "cmp")
    {
        return 1;
    }
    return 0;
}

