#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include "stack.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(5);
       ui->tableWidget->setColumnCount(1);
       ui->tableWidget->setVerticalHeaderLabels(QStringList() << "a" << "b" << "c" << "d" << "e");
       ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "");
       for(int i = 0; i < ui->tableWidget->rowCount(); i++){
           for(int j = 0; j < ui->tableWidget->columnCount(); j++){
               QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(0));
               ui->tableWidget->setItem(i, j, item);
           }
       }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CalculateButton_clicked()
{
    QString qstr = ui->ExpressionEdit->text(), polishRev;
    Operation* op = new Operation();
    polishRev = op->toPolish(qstr);
    ui->OpzEdit->setText(polishRev);
    char ch = 'a' - 1;
    double array[201] = {};
    for (int i = 0; i < op->Amount - 1; i++) {
        ch += 1;
        array[int(ch)] = ui->tableWidget->item(i, 0)->text().toDouble();
    }
    ui->ResultEdit->setText(op->Result(polishRev, array));
}










