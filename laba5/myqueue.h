#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <QMessageBox>
#include <vector>

using namespace std;

template<typename T>
class MyQueue
{
protected:

    template<typename S>
    class Node {
    public:
        T data;
        Node *next, *prev;
        Node (T data = T(), Node *next = NULL, Node *prev = NULL)
                {
                    this->data = data;
                    this->next = next;
                    this->prev = prev;
                }
    };

   public:
    Node <T> *head;
    Node <T> *tail;
    MyQueue<T>()
    {
        head = NULL;
        tail = NULL;
    }
    ~MyQueue<T>();
    vector<T> show();
    void add(T);
    void remove(); //удаляет элемент из начала очереди
    T showData();
    T searchMax(Node<T> *head);
    T searchMin(Node<T> *head);

};

template<typename T>
MyQueue<T>::~MyQueue()
{
    while(head)
    {
        tail = head->next;
        delete  head;
        head = tail;
    }
}

template<typename T>
void MyQueue<T>::add(T a)
{
    Node<T>* temp = new Node<T>;
    temp->next = NULL;
    temp->data = a;
    if(head)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        temp->prev = NULL;
        head = tail = temp;
    }
}

template<typename T>
void MyQueue<T>::remove()
{
    if(!head)
    {
        qDebug("Список пуст!");
        return;
    }
    Node<T> *temp;
    temp= head->next;
    delete head;
    head = temp;
}

template<typename T>
vector<T> MyQueue<T>::show()
{
    vector<T> vect;
    Node<T> *temp = tail;
    temp = head;
    while (temp)
    {
        vect.push_back(temp->data);
        temp = temp->next;
    }
    return vect;
}

template<typename T>
T MyQueue<T>::showData()
{
    return head->data;
}

template<typename T>
T MyQueue<T>::searchMax(Node<T> *head)
{
    Node<T> *tmp = head;
    int max = head->data;
    while (tmp)
    {
        if(max < tmp->data)
        {
            max = tmp->data;
        }
        tmp = tmp->next;
    }
    return max;
}

template<typename T>
T MyQueue<T>::searchMin(Node<T> *head)
{
    Node<T> *tmp = head;
    int min = head->data;
    while (tmp)
    {
        if(min > tmp->data)
        {
            min = tmp->data;
        }
        tmp = tmp->next;
    }
    return min;
}

#endif // MYQUEUE_H
