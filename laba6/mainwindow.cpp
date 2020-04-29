#include "mainwindow.h"
#include "ui_mainwindow.h"

unique_ptr<Tree> theTree(new Tree());
Node *root;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddButton_clicked()
{

    int k = (ui->KeyEdit->text()).toInt();
    string str = (ui->NameEdit->text()).toStdString();
    root = theTree->add(root, k, str);
    ui->listWidget->clear();
    ui->KeyEdit->clear();
    ui->NameEdit->clear();
}

void MainWindow::on_PreButton_clicked()
{
    ui->listWidget->clear();
    theTree->vect.clear();
    vector<Node> vect = theTree->PreOrderTree(root);
    for (int i = 0; i < (int)vect.size(); i++)
    {
        ui->listWidget->addItem(QString::number(vect[i].key) + " -- " + QString::fromStdString(vect[i].name));
    }
}

void MainWindow::print(Node *branch, QTreeWidgetItem *itm, int kl)
{

    if(!branch)
    {
        return;
    }
    if (kl == -1)
    {
        itm->setText(0, QString::number(branch->key));
        itm->setText(1, QString::fromStdString(branch->name));
        ui->treeWidget->addTopLevelItem(itm);
    }
    else
    {
        QTreeWidgetItem *child = new QTreeWidgetItem(2);
        child->setText(0, QString::number(branch->key));
        child->setText(1, QString::fromStdString(branch->name));
        itm->addChild(child);
        itm = child;
    }
    kl++;
    print(branch->left, itm, kl);
    print(branch->right, itm, kl);
    kl--;
}

int kl = -1;

void MainWindow::on_BuildTreeButton_clicked()
{
    ui->treeWidget->clear();
    QTreeWidgetItem *itm = new QTreeWidgetItem(2);
    print(root, itm, kl);
}

void MainWindow::on_PostButton_clicked()
{
    ui->listWidget->clear();
    theTree->vect.clear();
    vector<Node> vect = theTree->PostOrderTree(root);
    for (int i = 0; i < (int)vect.size(); i++)
    {
        ui->listWidget->addItem(QString::number(vect[i].key) + " -- " + QString::fromStdString(vect[i].name));
    }
}

void MainWindow::on_SymButton_clicked()
{
    ui->listWidget->clear();
    theTree->vect.clear();
    vector<Node> vect = theTree->SymmetricOrderTree(root);
    for (int i = 0; i < (int)vect.size(); i++)
    {
        ui->listWidget->addItem(QString::number(vect[i].key) + " -- " + QString::fromStdString(vect[i].name));
    }
}

void MainWindow::on_SearchButton_clicked()
{
    ui->listWidget->clear();
    int key = ui->KeyEdit->text().toInt();
    Node* s = theTree->find(root, key);
    ui->listWidget->addItem(QString::number(s->key)+" "+QString::fromStdString(s->name));
    ui->KeyEdit->clear();
    ui->NameEdit->clear();
}

void MainWindow::on_RemoveButton_clicked()
{
    ui->listWidget->clear();
    int key = ui->KeyEdit->text().toInt();
    root = theTree->remove(root, key);
    ui->KeyEdit->clear();
    ui->NameEdit->clear();
}

void MainWindow::on_ExButton_clicked()
{
    ui->listWidget->clear();
    int key = ui->KeyEdit->text().toInt();
    MyMiniTree *miniTree = new MyMiniTree();
    root = miniTree->ex(root, key);
    root = theTree->balance(root);
    ui->KeyEdit->clear();
    ui->NameEdit->clear();
}
