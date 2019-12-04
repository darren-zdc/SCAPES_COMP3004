#include "program.h"
#include <executecontrol.h>


Program::Program(string filename, string dir) : filename(filename), directory(dir)
{
    logger = Logger::getInstance();
}

Program::~Program()
{
    //deallocated statement vector
    delete logger;
    for (Statement* st :statements)
    {
        delete st;
    }
    for (Variable* var :variables)
    {
        delete var;
    }
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
                    logger->error("Invalid statement in line " + to_string(statements.size()));
                    return ERROR;
                }
            }
            else if (flag == ERROR)
            {
                logger->error("Failed to create statement \"" + line + "\"");
                return ERROR;
            }
        }
    }
    else if (myprogram.fail())
    {
        //failed to open a file
        logger->error("Failed to open file \"" + filename + "\" under \"" + directory + "\" directory");
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
    size_t index = 0;
    while(1)
    {
        Statement* st = statements.at(index);
        int status = st->run();
        if (status == ERROR)
        {
            //error when running
            logger->error("Runtime error in line "  + to_string(index+1));
            return ERROR;
        }
        else if (status == END )
        {
            logger->info("Run successfully!!");
            return SUCCESS;
        }
        if (jump)
        {
            int labelIndex  = findLabel(st->getOperands()[0].getValue());
            if (labelIndex < 0)
            {
                //Error label not found
                logger->error("Label not found for line " + to_string(index+1));
                return ERROR;
            }
            else
            {
                index = static_cast<size_t>(labelIndex);
            }
            jump = false;
        }
        else
        {
            index++;
        }

        if (index >= statements.size())
        {
            //Error index exceed statements size
            logger->error("No valid end statement");
            return ERROR;
        }
    }

}
int Program::createStatement(string instr, vector<string> operds, string label)
{
    if (instr == "dci")
    {
        //declares an integer variable
        statements.push_back(new DeclIntStmt(instr, operds, label));
    }
    else if (instr == "dca")
    {
        //declares an array
        statements.push_back(new DeclArrStmt(instr, operds, label));
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
    else if (instr == "mov")
    {
        //copies values
        statements.push_back(new MovStmt(instr, operds, label));
    }
    else if (instr == "add")
    {
        //adds values
        statements.push_back(new AddStmt(instr, operds, label));
    }
    else if (instr == "cmp")
    {
        //compares two values to test
        statements.push_back(new CompStmt(instr, operds, label));

    }
    else if (instr == "jls")
    {
        //jumps to the specified label if smaller
        statements.push_back(new JLessStmt(instr, operds, label));
    }
    else if (instr == "jmr")
    {
        //jumps to the specified label if greater
        statements.push_back(new JMoreStmt(instr, operds, label));
    }
    else if (instr == "jeq")
    {
        //jumps to the specified label if equal
        statements.push_back(new JEqStmt(instr, operds, label));
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
        logger->error("Invalid instruction " + instr);
        return ERROR;
    }
    statements.back()->setOperands(operds);
    statements.back()->setProgram(*this);
    return ERROR;
}

int Program::createStatement(string line, string label)
{
    vector<string> lineParses = HelperFunction::split(line);

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
    return SUCCESS;
}

int Program::createVariable(string name, int size)
{
    if(findVariable(name, nullptr))
    {
        return ERROR;
    }
    if (size == 0)
    {
        variables.push_back(new Variable(name));
    }
    else
    {
        variables.push_back(new Variable(name, size));
    }
    return SUCCESS;
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
    for(Variable* var:variables)
    {
        QJsonObject jVariable;
        jVariable["name"] = QString::fromStdString(var->getName());
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
    jsonFilename = directory + "/" + HelperFunction::getFileName("/" + this->filename, false) + ".json";
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
    Program* p = new Program(filenameFromJson, dir);
    QJsonArray sts = jProgram["statements"].toArray();
    foreach (const QJsonValue & st, sts)
    {
        QJsonObject jSt = st.toObject();
        QJsonArray jOperds = jSt["operands"].toArray();
        vector<string> operds;
        foreach (const QJsonValue & operand, jOperds)
        {
            operds.push_back(operand["name"].toString().toStdString());
            //qDebug() << QString::fromStdString(operand["name"].toString().toStdString());
        }
        //qDebug() << jSt["instruction"].toString();
        p->createStatement(jSt["instruction"].toString().toStdString(), operds, jSt["label"].toString().toStdString());
    }
    return p;
}

int Program::findVariable(string name, Variable** output)
{
    if (this->variables.empty())
    {
        return ERROR;
    }
    for(Variable* element: variables)
    {
        if (element->getName() == name)
        {
            if (output != nullptr)
                *output = element;
            return SUCCESS;
        }
    }
    return ERROR;
}

int Program::findLabel(string label)
{
    for (size_t i=0; i<statements.size(); i++)
    {
        if (statements.at(i)->getLabel()->getName() == label)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}


int Program::ifExistLabel(string name)
{
    for(Label element: labels)
    {
        if (element.getName() == name)
            return SUCCESS;
    }
    return ERROR;
}

int Program::ifPrevCompExist()
{
    if(statements.rbegin()[1]->getInstruction() == "cmp")
    {
        return SUCCESS;
    }
    return ERROR;
}

int Program::readInput(string varname)
{
    return control->readInput(varname);
}

int Program::setVariable(string name, int value, int index)
{
    Variable* var;
    if (!findVariable(name, &var))
    {
        //error variable not exist
        return ERROR;
    }
    if (var->isVarArray())
    {
        var->setValueByIndex(value, index);
    }
    else
    {
        var->setValue(value);
    }
    return SUCCESS;
}

void Program::setComparisonFlag(flag f)
{
    this->comparisonFlag = f;
}

void Program::setJump(bool b)
{
    this->jump = b;
}

flag Program::getComparisonFlag()
{
    return this->comparisonFlag;
}

string Program::getProgramOutput()
{
    return programOutput;
}

void Program::appendProgramOutput(string input)
{
    if (programOutput.empty())
    {
        programOutput = input + "#";
    }
    else
    {
        programOutput += input + "#";
    }
}

int Program::getValueByInput(string input)
{
    string index;
    Variable* var;
    string varname;
    if (HelperFunction::isNumber(input))
    {
        return stoi(input);
    }
    else if (findVariable(input, &var))
    {
        return var->getValue();
    }
    else if (HelperFunction::isArraySyntax(input, &varname, &index))
    {
        if (findVariable(varname, &var))
        {
            //if the input index is a number
            if (HelperFunction::isNumber(index))
            {
                int i = stoi(index);
                if (var->isVarArray() && i < var->getSize() && i >= 0)
                {
                    return var->getValueByIndex(i);
                }
                else
                {
                    logger->error("Index out of bound.");
                    return -1;
                }
            }
            //if the input the not a number
            else
            {
                Variable* indexVar;
                if (findVariable(index, &indexVar))
                {
                    if (var->isVarArray() && indexVar->getValue() < var->getSize() && indexVar->getValue() >= 0)
                    {
                        return var->getValueByIndex(indexVar->getValue());
                    }
                    else
                    {
                        logger->error("Index out of bound.");
                        return -1;
                    }
                }
                else
                {
                    logger->error("Index variable not find");
                    return -1;
                }
            }

        }
        logger->error("Variable not exist");
        return -1;
    }
    else
    {
        //Error invalid input
        logger->error("Invalid input " + input);
        return -1;
    }
}

// arrayToInt(): takes a operand and return its index value
/*
int Program::arrayToInt(const string& s)
{
    size_t posOfPlus = s.find("+"); // posistion of the "+" symbol in the operand
    string varName = s.substr(1,posOfPlus-1);
    int index;

    if(s.substr(0,1) != "$")
    {
        // error: doesn't strart with $
        return -1;
    }

    if(!ifExistVariable(varName, nullptr))
    {
        //error: variable doesn't exist
        return -1;
    }
    else
    {
        if(!findVariable(varName, nullptr)->isVarArray())
        {
            //variable exist but is not an array variable
            return -1;
        }
    }

    if(!HelperFunction::isNumber(s.substr(posOfPlus+1)))
    {
        // whatever after the "+" sign is not an integer
        return -1;
    }
    else
    {
        index = std::stoi(s.substr(posOfPlus+1));
    }
    
    if((!findVariable(varName)->getSize()) <= 0 || (!findVariable(varName)->getSize()) > index){
        // index out of bound
        return -1;
    }
    
    // return the value
    return findVariable(varName)->getValueByIndex(index);

}
*/
