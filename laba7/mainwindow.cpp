#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hash.h"
#include "myhash.h"
#include <QMessageBox>

hashTab *Hash = new hashTab();


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


void MainWindow::on_AddButton_clicked()
{
    int key = ui->KeyEdit->text().toInt();
    string str = ui->NameEdit->text().toStdString();
    Node *tmp = new Node(key, str);
    Hash->add(tmp);
    print(Hash);
    ui->KeyEdit->clear();
    ui->NameEdit->clear();
}

void MainWindow::on_RemoveButton_clicked()
{
    int key = ui->KeyEdit->text().toInt();
    Hash->remove(key);
    print(Hash);
}

void MainWindow::on_SearchButton_clicked()
{
    ui->listWidget->clear();
    int key = ui->KeyEdit->text().toInt();
    Node* tmp;
    tmp = Hash->search(key);
    if (!tmp)
    {
        QMessageBox::critical(this, "CRITICAL!", "TRY AGAIN.");
        exit(0);
    }
    ui->listWidget->addItem(QString::number(tmp->key) + " " + QString::fromStdString(tmp->name));
    ui->KeyEdit->clear();
    ui->NameEdit->clear();
}

void MainWindow::on_ShowButton_clicked()
{
    print(Hash);
}

void MainWindow::print(hashTab* data)
{
    ui->listWidget->clear();
    for(int i = 0; i < SIZE; i++){
            if(data->hashTable[i] != NULL){
                ui->listWidget->addItem(QString::number( data->hashTable[i]->key) + " " + QString::fromStdString( data->hashTable[i]->name));
            }
        }
}

void MainWindow::on_ExButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    MyHash *myHash = new MyHash();
    ui->listWidget->clear();
    srand((unsigned int)time(NULL));
    int k;
    string str;
    for(int i = 0; i < 20; i++)
    {
        k = rand()%21 - 10;
        str = 97 + i;
        Node* tmp = new Node(k, str);

        myHash->add(tmp);
    }
    for(int i = 0; i < SIZE; i++){
            if(myHash->hashTable[i] != NULL){
                ui->listWidget_2->addItem(QString::number( myHash->hashTable[i]->key) + " " + QString::fromStdString( myHash->hashTable[i]->name));
            }
        }
    myHash->ex();
    print(myHash);

}
















