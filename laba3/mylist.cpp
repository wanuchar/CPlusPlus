#include "mylist.h"

using namespace std;

Enrolle::Enrolle(string sname, vector<int> vmarks)
{
    name = sname;
    marks = vmarks;
    next = nullptr;
}



MyList::MyList()
{
    head = NULL;
    tail = NULL;
}

MyList::~MyList()
{
    Enrolle* next = nullptr;
    while (head)
    {
        next = head->next;
        delete head;
        head = next;
    }
}

void MyList::add(Enrolle *item)
{
    if(!head)
    {
        head = item;
    }
    else
    {
        tail->next = item;
    }
    tail = item;
}

void MyList::add(Enrolle *item, int ind)
{
    if(!head)
    {
        head = item;
        tail = item;
    }
    else if (ind == 0)
    {
        item->next = head;
        head = item;
    }
    else
    {
        Enrolle* current = head;
        for (int i = 1; i < ind && current->next; i++)
        {
            current = current->next;
        }

        if(!current->next)
        {
            tail = item;
        }

        item->next = current->next;
        current->next = item;
    }
}


void MyList::remove(int ind)
{
    if (!head)
    {
        return;
    }

    if (ind == 0)
    {
        Enrolle* oldHead = head;
        head = oldHead->next;
        delete oldHead;
        return;
    }

    Enrolle* prev = head;
    Enrolle* current = head->next;

    for (int i = 1; current; i++)
    {
        if(i == ind)
        {
            if(!current->next)
            {
                tail = prev;
            }

            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

Enrolle* MyList::search(string nameSearch)
{
    Enrolle* current = head;
    string buff;
    while (current)
    {
        istringstream ist(current->name);
        ist >> buff;
        if (buff == nameSearch)
        {
            return current;
        }
        current = current->next;
    };
    return nullptr;
}























