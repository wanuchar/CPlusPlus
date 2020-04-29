#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include "tree.h"
#include "myminitree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();
    void print(Node *branch, QTreeWidgetItem *itm, int kl);
    void on_PreButton_clicked();

    void on_BuildTreeButton_clicked();

    void on_PostButton_clicked();

    void on_SymButton_clicked();

    void on_SearchButton_clicked();

    void on_RemoveButton_clicked();

    void on_ExButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
