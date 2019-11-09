#include "mainwindow.h"
#include <uimanager.h>
#include <ui_mainwindow.h>
#include <QStringListModel>

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

void MainWindow::attachDependancies(uimanager *manager) //connects the mainwindow pointes to the relevant ui elements for future use
{
    this->manager = manager;
    this->namelist = manager->PollProgramList();
    this->textbox = this->findChild<QTextEdit *>("BottomText"); //setup bottom text box
    textbox->setReadOnly(true);
    this->texteditor = this->findChild<QTextEdit *>("TextEditor"); //setup text editor
    texteditor->setVisible(false);
    this->listview = this->findChild<QListView *>("ProgramList"); //setup program list
    QStringListModel *model = new QStringListModel;
    model->setStringList(namelist);
    listview->setModel(model);
    listview->setEditTriggers(QAbstractItemView::NoEditTriggers); //removes ability for user to edit list

}

void MainWindow::on_CreateButton_clicked() //sends command to create a file, then update the program list
{
    if (texteditor->isVisible() == false)
    {
        textbox->setText("Created New File");
        manager->RecieveSignal("create", "null", "null");
        if (manager->PollProgramList().size() != 0)
        {
            QStringListModel *model = new QStringListModel;
            model->setStringList(manager->PollProgramList());
            listview->setModel(model);
        }
    }
}

void MainWindow::on_CompileButton_clicked() //sends compile command, then update the program list
{
    if (this->listview->currentIndex().isValid() && texteditor->isVisible() == false)
    {
        QModelIndex index = this->listview->currentIndex();
        QString name = index.data(Qt::DisplayRole).toString();
        textbox->setText("Compiling File ");
        textbox->append(name);
        manager->RecieveSignal("compile", name, "null");
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
        textbox->setText("Running File ");
        textbox->append(name);
        manager->RecieveSignal("run", name, "null");
        //if (manager->PollProgramList().size() != 0)
        //{
          //  QStringListModel *model = new QStringListModel;
          //  model->setStringList(manager->PollProgramList());
          //  listview->setModel(model);
        //}
    }
}

void MainWindow::on_SaveButton_clicked() //send save command
{
    if (texteditor->isVisible())
    {
        //TODO update save signal with actual save data
        QString temp = texteditor->toPlainText();
        manager->RecieveSignal("save", textbox->toPlainText(), temp);
    }
}

void MainWindow::on_OpenButton_clicked() //send open command
{
    if (this->listview->currentIndex().isValid() && texteditor->isVisible() == false)
    {
        QModelIndex index = this->listview->currentIndex();
        QString name = index.data(Qt::DisplayRole).toString();
        textbox->setText(name);
        //manager->RecieveSignal("open", name, "null");
        QStringList contents = manager->PollFileContents(name);
        for (int i = 0; i < contents.size(); i++)
        {
            texteditor->append(contents[i]);
        }
        texteditor->setVisible(true);
        listview->setVisible(false);
        textbox->setReadOnly(false);
    }
}

void MainWindow::on_CloseButton_clicked() //send close command, then update program list
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
    }
}
