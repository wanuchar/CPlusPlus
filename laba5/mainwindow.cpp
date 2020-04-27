#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <ctime>
#include <cstdlib>
#include "queue.h"

MyQueue<int> *queue = new MyQueue<int>();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChooseButton_clicked()
{
    srand(unsigned(time(NULL)));
    int ind = ui->SizeComboBox->currentIndex() + 1;
    int a;
    for (int i = 0; i < ind; i++) {
        a = rand()%21+1;
        queue->add(a);
    }
}

void MainWindow::on_ShowButton_clicked()
{
    ui->list->clear();
    vector<int> vect = queue->show();
    for (unsigned long i = 0; i < vect.size(); i++)
    {
        ui->list->addItem(QString::number(vect[i]));
    }
}

void MainWindow::on_AddButton_clicked()
{
     QString qstr = ui->AddEdit->text();
     int a = qstr.toInt();

     queue->add(a);
}

void MainWindow::on_RemoveOneButton_clicked()
{
    queue->remove();
}

void MainWindow::on_RemoveAllButton_clicked()
{
    queue->~MyQueue<int>();
    ui->list->clear();
}

void MainWindow::on_ExButton_clicked()
{
    ui->listWidget->clear();
    Queue<int> *q = new Queue<int>();
    q = q->ex(queue);
    vector<int> vect = q->show();
    for (unsigned long i = 0; i < vect.size(); i++)
    {
        ui->listWidget->addItem(QString::number(vect[i]));
    }

}
