#include "LinkedList.h"

template <class Type>
Node<Type>::Node(const Type& val): item(val){
    next = prev = 0;
}

template <class Type>
LinkedList<Type>::LinkedList(){
    front = back = 0;
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

template <class Type>
Iterator<Type>::Iterator(const LinkedList<Type> &ll){
    list = ll;
    current_node = list->front;
}

template <class Type>
Iterator<Type>::~Iterator(){
    delete list;
}

template <class Type>
void Iterator<Type>::insert(const Type& val){
    // if inserting at the end need to update back
    Node<Type>* nn = new Node<Type>(val);

    // update front and back as necessary
    if(list->is_empty()){
        list->front = list->back = nn;
    }

    else if(list->back == current_node){
        list->back = nn;
    }

    nn->next = current_node->next;
    nn->prev = current_node;
    current_node->next->prev = nn;
    current_node->next = nn;

    // advance the iterator to now point at the newly inserted node
    current_node = nn;
}

template <class Type>
Type Iterator<Type>::remove(){
    if(list->is_empty()){
        cerr << "Error: can't remove node from an empty list.\n";
        exit(-1);
    }
    else{
        Node<Type>* ptr = current_node;
        Type val = current_node->item;

        if(current_node->prev){
            current_node->prev->next = current_node->next;
            current_node = ptr->prev;
        }
        else{
            list->front = current_node->next; 
            current_node = list->front;
        }

        if(current_node->next){
            current_node->next->prev = current_node->prev;
            current_node = ptr->next;
        }
        else{
            list->back = current_node->prev;
            current_node = list->back;
        }
        
        delete ptr;
        
        return val;
    }
}

// Prefix increment
template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    current_node = current_node->next;
    return *this;
}

// Prefix decrement 
template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    current_node = current_node->prev;
    return *this;
}

// Postfix increment
template<class Type>
Iterator<Type> Iterator<Type>::operator++(int i)
{
    // TODO use i for variable sized increments
    Iterator<Type> temp = *this;
    ++*this;
    return temp;
}

// Postfix increment
template<class Type>
Iterator<Type> Iterator<Type>::operator--(int i)
{
    // TODO use i for variable sized increments
    Iterator<Type> temp = *this;
    --*this;
    return temp;
}


