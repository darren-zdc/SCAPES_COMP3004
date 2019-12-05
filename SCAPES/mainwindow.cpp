#include "mainwindow.h"
#include "helperfunction.h"
#include <uimanager.h>
#include <ui_mainwindow.h>
#include <QStringListModel>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :   //setup use of UI file
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() //destructor
{
    delete ui;
    delete manager;
    delete textbox;
    delete listview;
}

QTextEdit* MainWindow::getBottomBox()
{
    return textbox;
}
void MainWindow::attachDependancies(uimanager *manager) //connects the mainwindow pointes to the relevant ui elements for future use
{
    this->manager = manager;
    this->namelist = manager->PollProgramList();
    this->textbox = this->findChild<QTextEdit *>("BottomText"); //setup bottom text box
    textbox->setReadOnly(true);
    this->texteditor = this->findChild<QTextEdit *>("TextEditor"); //setup text editor
    texteditor->setVisible(false);
    this->listview = this->findChild<QListView *>("ProgramList"); //setup program list
    this->CreateButton = this->findChild<QPushButton *>("CreateButton"); //setup ui buttons
    this->RunButton = this->findChild<QPushButton *>("RunButton");
    this->OpenButton = this->findChild<QPushButton *>("OpenButton");
    this->CloseButton = this->findChild<QPushButton *>("CloseButton");
    CloseButton->setEnabled(false);
    CloseButton->setVisible(false);
    this->SaveButton = this->findChild<QPushButton *>("SaveButton");
    SaveButton->setEnabled(false);
    SaveButton->setVisible(false);
    this->CompileButton = this->findChild<QPushButton *>("CompileButton");
    QStringListModel *model = new QStringListModel;
    model->setStringList(namelist);
    listview->setModel(model);
    listview->setEditTriggers(QAbstractItemView::NoEditTriggers); //removes ability for user to edit list

}

void MainWindow::on_CreateButton_clicked() //sends command to create a file, then update the program list
{
    if (texteditor->isVisible() == false)
    {
        textbox->setText(QString::fromStdString(HelperFunction::getCurrentTime()) + " Created New File");
        manager->RecieveSignal("create", "null", "null");
        if (manager->PollProgramList().size() != 0)
        {
            QStringListModel *model = new QStringListModel;
            model->setStringList(manager->PollProgramList());
            listview->setModel(model);
        }
        QMessageBox message;
        message.setText("Blank File Created");
        message.exec();
    }
}

void MainWindow::on_CompileButton_clicked() //sends compile command, then update the program list
{
    if (this->listview->currentIndex().isValid() && texteditor->isVisible() == false)
    {
        QModelIndex index = this->listview->currentIndex();
        QString name = index.data(Qt::DisplayRole).toString();
        if (name.endsWith(".txt")) //can only compile .txt files
        {
            textbox->setText(QString::fromStdString(HelperFunction::getCurrentTime()) + " Compiling File " + name);
            manager->RecieveSignal("compile", name, "null");
        }
        if (manager->PollProgramList().size() != 0)
        {
            QStringListModel *model = new QStringListModel;
            model->setStringList(manager->PollProgramList());
            listview->setModel(model);
        }
    }
}

void MainWindow::on_RunButton_clicked() //sends run command, then update the program list
{
    if (this->listview->currentIndex().isValid() && texteditor->isVisible() == false)
    {
        QModelIndex index = this->listview->currentIndex();
        QString name = index.data(Qt::DisplayRole).toString();
        textbox->setText(QString::fromStdString(HelperFunction::getCurrentTime()) + " Running File " + name);
        manager->RecieveSignal("run", name, "null");
    }
}

void MainWindow::on_SaveButton_clicked() //send save command
{
    if (texteditor->isVisible() && manager->openFile.endsWith(".txt"))
    {
        QString temp = texteditor->toPlainText();
        manager->RecieveSignal("save", "null", temp);
        manager->RecieveSignal("rename", "null", textbox->toPlainText());
    }
}

void MainWindow::on_OpenButton_clicked() //send open command, alternate visible ui buttons
{
    if (this->listview->currentIndex().isValid() && texteditor->isVisible() == false)
    {
        QModelIndex index = this->listview->currentIndex();
        QString name = index.data(Qt::DisplayRole).toString();
        textbox->setText(name);
        manager->openFile = name;
        QStringList contents = manager->PollFileContents(name);
        for (int i = 0; i < contents.size(); i++)
        {
            texteditor->append(contents[i]);
        }
        texteditor->setVisible(true);
        if (name.QString::toStdString().substr(name.length() -4, name.length() - 1) == ".txt")
            texteditor->setReadOnly(false);
        else
            texteditor->setReadOnly(true);
        listview->setVisible(false);
        if (name.QString::toStdString().substr(name.length() -4, name.length() - 1) == ".txt")
            textbox->setReadOnly(false);
        else
            textbox->setReadOnly(true);

        OpenButton->setEnabled(false);
        CompileButton->setEnabled(false);
        RunButton->setEnabled(false);
        CreateButton->setEnabled(false);
        OpenButton->setVisible(false);
        CompileButton->setVisible(false);
        RunButton->setVisible(false);
        CreateButton->setVisible(false);

        CloseButton->setEnabled(true);
        SaveButton->setEnabled(true);
        CloseButton->setVisible(true);
        SaveButton->setVisible(true);
    }
}

void MainWindow::on_CloseButton_clicked() //send close command, then update program list and alternate visible ui elements
{
    if (texteditor->isVisible())
    {
        textbox->clear();
        manager->RecieveSignal("close", "null", "null");
        if (manager->PollProgramList().size() != 0)
        {
            QStringListModel *model = new QStringListModel;
            model->setStringList(manager->PollProgramList());
            listview->setModel(model);
        }
        texteditor->setVisible(false);
        texteditor->clear();
        listview->setVisible(true);
        textbox->setReadOnly(true);

        OpenButton->setEnabled(true);
        CompileButton->setEnabled(true);
        RunButton->setEnabled(true);
        CreateButton->setEnabled(true);
        OpenButton->setVisible(true);
        CompileButton->setVisible(true);
        RunButton->setVisible(true);
        CreateButton->setVisible(true);

        CloseButton->setEnabled(false);
        SaveButton->setEnabled(false);
        CloseButton->setVisible(false);
        SaveButton->setVisible(false);
    }
}

void MainWindow::on_actionChange_Language_triggered()
{
    QMessageBox message;
    message.setText("Language change functionality is not required, this option is visible for the sake of completeness in regards to the original SCAPES project description.");
    message.exec();
}

void MainWindow::on_actionChange_Directory_triggered() //allows navigation to change directory, input will be ignored if user does not have required permission
{
    QString fileName = QFileDialog::getExistingDirectory(this, tr("Set Directory"), manager->getDirectory());

    int i = manager->SetDirectory(fileName, userType);

    if (i == 0)
    {
        this->displayInBox("You don't have access to this feature.");
    }
    if (manager->PollProgramList().size() != 0)
    {
        QStringListModel *model = new QStringListModel;
        model->setStringList(manager->PollProgramList());
        listview->setModel(model);
    }
}

void MainWindow::on_actionAdmin_Options_triggered() //alternates between programmer and system admin user type, TODO change to logout button
{
    if (userType == "programmer")
        userType = "systemAdmin";
    else
        userType = "programmer";

    QMessageBox message;
    message.setText("User type changed to: " + userType);
    message.exec();
}

void MainWindow::displayInBox(QString text)
{
    QMessageBox message;
    message.setWindowTitle("System Message");
    message.setText(text);
    message.exec();
}

void MainWindow::displayLoggerMessage(QString text)
{
    textbox->append(text);
}

void MainWindow::displayInPopup(QStringList output, QString source) //displays a programs output
{
    if (source == QString::fromStdString("Program"))
    {
        QMessageBox message;
        message.setWindowTitle("Output");
        QString text;
        text.append("<b>Program Output: </b> <br>");
        for (int i = 0; i < output.size(); i++)
        {
            text.append(output[i] + "<br>");
        }
        message.setText(text);
        message.exec();
    }
    else if (source == QString::fromStdString("Logger"))
    {

        QMessageBox message;
        message.setWindowTitle("Logger Message");
        QString text;
        text.append("<b>Logger: </b> <br>");
        for (int i = 0; i < output.size(); i++)
        {
            text.append(output[i] + "<br>");
        }
        message.setText(text);
        message.exec();

    }
    else if (source == QString::fromStdString("Input"))
    {
        QMessageBox message;
        message.setWindowTitle("Input Error");
        QString text;
        text.append("<b>Invalid Input: </b> <br>");
        for (int i = 0; i < output.size(); i++)
        {
            text.append(output[i] + "<br>");
        }
        message.setText(text);
        message.exec();
    }
}

int MainWindow::requestInput(QString name)
{
    bool success = false;

    int value = QInputDialog::getInt(this, tr("Input Required"), "Input value for " + name, 0, -2147483647, 2147483647, 1, &success);

    if (success)
    {
        return value;
    }
    else
    {
        QStringList temp;
        temp.append("Input required, defaulting to 0");
        this->displayInPopup(temp, QString::fromStdString("Input"));
        int value = 0;
        return value;
    }
}
