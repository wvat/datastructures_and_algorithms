// Based on an example taken from chapter 7 of C++ Primer 2nd edition by Stanley B. Lippman
#ifndef QUEUE_H
#define QUEUE_H

// forward declaration
template<class Type>
class Queue;

template<class Type>
class QueueItem{
public:
    // this creates a 1:1 pairing between a queue and the queue items for each type
    friend class Queue<Type>;

    // pass by const reference incase the data type is large
    QueueItem(const Type&);

    friend ostream& operator<<(ostream& os, QueueItem<Type>& qi)
    {
        os << qi.item;
        return os;
    }

private:
    Type item;
    QueueItem* next;
};

template<class Type>
class Queue{
public:
    Queue();
    ~Queue();
    void enqueue(const Type&);
    Type dequeue();
    bool is_empty();
    friend ostream& operator<<(ostream& os, Queue<Type>& q)
    {
        QueueItem<Type> *p;
        for(p=q.front; p; p=p->next)
        {
            os << *p << " ";
        }
        return os;
    }
private:
    // need to specifiy parameter list for QueueItem
    // because it isn't clear which instance of QueueItem is 
    // being referenced
    QueueItem<Type> *front;
    QueueItem<Type> *back;
};

#endif