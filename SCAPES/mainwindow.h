#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QTextEdit>
#include <QPushButton>

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
    void displayInBox(QString text);
    void displayInPopup(QStringList output, QString source);
    int requestInput(QString name);
    QTextEdit* getBottomBox();
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
    QPushButton *CloseButton;
    QPushButton *OpenButton;
    QPushButton *CompileButton;
    QPushButton *RunButton;
    QPushButton *SaveButton;
    QPushButton *CreateButton;

    void UpdateProgramList(QStringList);
};

#endif // MAINWINDOW_H
