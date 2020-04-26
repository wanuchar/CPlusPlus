#ifndef MYLIST_H
#define MYLIST_H

#include <string>
#include <sstream>
#include <vector>
#include "myexception.h"

using namespace std;

class Enrolle
{
    public:
    string name;
    vector<int> marks;
    Enrolle* next;
    Enrolle(string sname, vector<int> vmarks);
};

class MyList
{

public:
    Enrolle* head;
    Enrolle* tail;

    MyList();
    ~MyList();
    void add(Enrolle* item);
    void add(Enrolle* item, int ind);
    void remove(int ind);
    Enrolle* search(string nameSearch);
};

#endif // MYLIST_H
