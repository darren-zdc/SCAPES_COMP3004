#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QTextEdit>

class uimanager;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void attachDependancies(uimanager *manager);
    void displayMessage(int flag);
    ~MainWindow();

private slots:

    void on_CreateButton_clicked();

    void on_CompileButton_clicked();

    void on_RunButton_clicked();

    void on_SaveButton_clicked();

    void on_OpenButton_clicked();

    void on_CloseButton_clicked();

    void on_actionChange_Language_triggered();

    void on_actionChange_Directory_triggered();

    void on_actionAdmin_Options_triggered();

private:
    Ui::MainWindow *ui;
    uimanager *manager;
    QString userType = "programmer";
    QStringList namelist;
    QListView *listview;
    QTextEdit *textbox;
    QTextEdit *texteditor;
    void UpdateProgramList(QStringList);
};

#endif // MAINWINDOW_H
