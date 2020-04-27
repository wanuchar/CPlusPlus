#ifndef QUEUE_H
#define QUEUE_H

#include "myqueue.h"

template<typename T>
class Queue :public MyQueue<T>
{
public:
    Queue<T>();
    Queue<T>* ex(MyQueue<T>*);
};

template<typename T>
Queue<T>::Queue()
{
}

template<typename T>
Queue<T>* Queue<T>::ex(MyQueue<T>* queue)
{
    Queue* q = new Queue(), trash;
    int min = queue->searchMin(queue->head), max = queue->searchMax(queue->head);
    while((queue->head)->next )
    {
        if(queue->showData() == min)
        {
            q->add(queue->showData());
            while (queue->showData() != max) {
                trash.add(queue->showData());
                queue->head = (queue->head)->next;
            }
         while((queue->head)->next )
         {
              q->add(queue->showData());
              queue->head = (queue->head)->next;
         }
         q->add(queue->showData());
         break;
        }
        else if (queue->showData() == max)
        {
            q->add(queue->showData());
            while (queue->showData() != min) {
                trash.add(queue->showData());
                queue->head = (queue->head)->next;
            }

         while((queue->head)->next != NULL)
         {
              q->add(queue->showData());
              queue->head = (queue->head)->next;
         }
         q->add(queue->showData());
         break;
        }
        q->add(queue->showData());
        queue->head = (queue->head)->next;
    }
    return q;
}

#endif // QUEUE_H
