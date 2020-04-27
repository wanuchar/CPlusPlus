#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_ChooseButton_clicked();

    void on_ShowButton_clicked();

    void on_AddButton_clicked();

    void on_RemoveOneButton_clicked();

    void on_RemoveAllButton_clicked();

    void on_ExButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
