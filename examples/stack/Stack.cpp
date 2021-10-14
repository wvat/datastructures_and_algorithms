#include "Stack.h"

template<class Type>
StackItem<Type>::StackItem(const Type &val): item(val){
    next = 0;
}

template<class Type>
Stack<Type>::Stack(){
    front = 0;
}

template<class Type>
Stack<Type>::~Stack(){
    StackItem<Type>* ptr;
    for(ptr=front; ptr; ptr=ptr->next())
        delete ptr;
    // or could use is_empty with pop
}

template<class Type>
bool Stack<Type>::is_empty()
{
    return front == 0;
}

template<class Type>
Type Stack<Type>::peek(){
    return front->item;
}

template<class Type>
Type Stack<Type>::pop(){

    if(is_empty())
    {
        cerr << "Error: tried to use pop() on an empty stack.";
        exit(-1);
    }

    StackItem<Type>* ptr;
    ptr = front;
    Type val = ptr->item;
    front = front->next;
    delete ptr;
    return val;
}

template<class Type>
void Stack<Type>::push(const Type& val){
    StackItem<Type>* si = new StackItem<Type>(val);

    if(is_empty())
        front = si;
    else{
        si->next = front;
        front = si;
    } 
    return;
}
