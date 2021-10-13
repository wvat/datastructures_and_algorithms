// Based on an example taken from chapter 7 of C++ Primer 2nd edition by Stanley B. Lippman
#include "Queue.h"

// if we initialize the item with the argument in the body
// of the constructor, we essentially are calling the constructor of 't' twice
// Once when the QueueItem constructor is called 
// And again when the argument is assigned to our item variable.
// An explicit initializaion solves this issue
template<class Type>
QueueItem<Type>::QueueItem(const Type &t) : item(t)
{ next = 0; }

/*template<class Type>
ostream& operator<<(ostream& os, QueueItem<Type>& qi)
{
    os << qi.item;
    return os;
}*/
// end QueueItem

template<class Type>
Queue<Type>::Queue()
{
    front = 0;
    back = 0;
}

template<class Type>
Queue<Type>::~Queue()
{
    while (!is_empty())
        dequeue();
}

template<class Type>
void Queue<Type>::enqueue(const Type& val)
{
    QueueItem<Type>* ptr = new QueueItem<Type>(val);
    if(is_empty())
        front = back = ptr;
    else{
        back->next = ptr;
        back = ptr;
    }
}

template<class Type>
Type Queue<Type>::dequeue()
{
    if(is_empty())
    {
        std::cerr << "Error: dequeue() performed on an empty queue.\n";
        exit(-1);
    }

    // need an explicit pointer so we can delete the front node
    QueueItem<Type> * ptr = front;
    front = front->next;
    Type val = ptr->item;
    delete ptr;
    return val;
}

template<class Type>
bool Queue<Type>::is_empty()
{
    return front == 0;
}

/*template<class Type>
ostream& operator<<(ostream& os, Queue<Type>& q)
{
    //QueueItem<Type> *p;
    //for(p=q.front; p; p=p->next)
    //    os << *p << " ";
    os << "Hello!";
    return os;
}*/