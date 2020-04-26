#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
#include <QString>
#include <cmath>
#include <QMessageBox>


using namespace std;

class Stack
{
    public:
    char data;
    Stack* next;
};

class Operation
{
public:
    Stack* begin;
    Operation();
    int Prior(char);//приоритет операций
    Stack* InStack(Stack*, char); //push
    Stack* OutStack(Stack*, char*);//pop
    QString Result(QString, double*);
    QString toPolish(QString);
    int Amount = 6;
};

#endif // STACK_H
