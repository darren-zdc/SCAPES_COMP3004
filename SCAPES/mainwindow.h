#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <uimanager.h>
#include <QStringListModel>
#include <QListView>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void attachDependancies(uimanager *manager);
    ~MainWindow();

private slots:

    void on_CreateButton_clicked();

    void on_CompileButton_clicked();

    void on_RunButton_clicked();

    void on_SaveButton_clicked();

    void on_OpenButton_clicked();

    void on_CloseButton_clicked();

private:
    Ui::MainWindow *ui;
    uimanager *manager;
    QStringList namelist;
    QListView *listview;
    QTextEdit *textbox;
    QTextEdit *texteditor;
    void UpdateProgramList(QStringList);
};

#endif // MAINWINDOW_H
