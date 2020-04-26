#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylist.h"
#include "myexception.h"
#include "QMessageBox"
#include "QString"

MyList* List = new MyList();

using namespace std;

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


void MainWindow::on_addButton_clicked()
{
    QString qstr = ui->nameEdit->text();
    string str = qstr.toStdString();
    QString qmarks = ui->markEdit->text();
    int place;

    QStringList list1 = qmarks.split(',', QString::SkipEmptyParts);
    vector<int> imarks;
    for (int i = 0; i < list1.length(); i++)
    {
        imarks.push_back(list1[i].toInt());
    }

    qstr = ui->placeEdit->text();



    Enrolle* enrolle = new Enrolle (str, imarks);
    if (!qstr.isEmpty())
    {
        place = qstr.toInt();
        List->add(enrolle, place);
    } else List->add(enrolle);

    ui->nameEdit->clear();
    ui->markEdit->clear();
    ui->placeEdit->clear();
}

void MainWindow::on_showAllButton_clicked()
{
    ui->listWidget->clear();
    if(!List->head)
    {
     qDebug("Ошибка");
    }
    QString qstr;

    Enrolle* tmp = List->head;
    while(tmp)
    {
        qstr = QString::fromStdString(tmp->name);
        ui->listWidget->addItem(qstr);
        tmp = tmp->next;
    }
}

void MainWindow::on_removeButton_clicked()
{
    int rowNum = -1;
    try {
          rowNum = ui->listWidget->currentRow();
          if(rowNum == -1)
          {
              throw MyException("Try again.\n");
          }
    } catch (MyException &exception) {
         QMessageBox::critical(this,"CRITICAL!","An array exception occurred (" + QString::fromStdString(exception.what()) + ")\n");
    }
    catch (exception &exception)
        {
             QMessageBox::critical(this,"CRITICAL!","Some other std::exception occurred (" + QString::fromStdString(exception.what()) + ")\n");
        }

        List->remove(rowNum);

}

void MainWindow::on_searchButton_clicked()
{
    QString qstr = ui->nameEdit->text();
    if (!qstr.isEmpty())
    {
    string str = qstr.toStdString();

    ui->listWidget->clear();
    Enrolle* tmp = List->search(str);
    Enrolle* temp;


      while (tmp)
       {
        float av = 0;
         MyList* list = new MyList();

        qstr = QString::fromStdString(tmp->name);
        qstr.append("\nMarks: ");
        for (unsigned long i = 0; i < (tmp->marks).size(); i++)
         {
            av += (tmp->marks)[i];
            qstr.append(QString::number((tmp->marks)[i]));
            if (i != (tmp->marks).size() - 1) {
                qstr.append(", ");
            }
         }

        av /= (float)(tmp->marks).size();
        qstr.append("\nAverage mark: ");
        qstr.append(QString::number(av));

        ui->listWidget->addItem(qstr);

        temp = tmp->next;
        if (!temp)
            break;
        while (temp)
        {
            list->add(temp);
            temp = temp->next;
        }
         tmp = list->search(str);
         if (!tmp)
             break;
       }
    }
    else
    {
        qDebug("Ошибка");
    }
}

void MainWindow::on_showTheBestButton_clicked()
{
    ui->listWidget->clear();
    int sum = 0, markAmount = 0;
    Enrolle* temp = List->head;
    while (temp)
    {
        for (unsigned long i = 0; i < (temp->marks).size(); i++)
        {
            sum+=(temp->marks)[i];
        }
        markAmount+=(temp->marks).size();

        temp = temp->next;
    }

    sum /= markAmount;

    temp = List->head;

    int av = 0;
     QString qstr;

    while (temp)
    {
        for (unsigned long i = 0; i < (temp->marks).size(); i++)
         {
            av += (temp->marks)[i];
         }

        av /= (temp->marks).size();

        if(av >= sum)
        {
            qstr = QString::fromStdString(temp->name);
            qstr.append("\nAverag mark: ");
            qstr.append(QString::number(av));
            ui->listWidget->addItem(qstr);
        }
        av = 0;
        temp = temp->next;
    }
}










