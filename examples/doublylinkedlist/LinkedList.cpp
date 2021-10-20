#include "LinkedList.h"

template <class Type>
Node<Type>* LinkedList<Type>::front = 0;

template <class Type>
Node<Type>::Node(const Type& val): item(val){
    next = prev = 0;
}

template <class Type>
LinkedList<Type>::~LinkedList<Type>(){
    while (!is_empty())
        remove();
}

// Add a node to the end of the list
template <class Type>
void LinkedList<Type>::add(const Type& val){
    Node<Type>* n  = new Node<Type>(val);
    
    if(is_empty())
        front = back = n;
    else{
        back->next = n;
        n->prev = back;
        back = n;
    }
}

// Remove a node from the front of the list
template <class Type>
Type LinkedList<Type>::remove(){
    if(is_empty())
        cerr << "Error: tried to remove a node from an empty list.";
        exit(-1);

    Node<Type>* ptr = front;
    Type val = ptr->item;
    front = front->next;
    front->prev = 0;
    delete ptr;
    return val;
}

template <class Type>
bool LinkedList<Type>::is_empty(){
    return front == 0;
}