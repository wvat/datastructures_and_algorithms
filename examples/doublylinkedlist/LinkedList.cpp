#include "LinkedList.h"

template <class Type>
Node<Type>* LinkedList<Type>::front = 0;

template <class Type>
Node<Type>* LinkedList<Type>::back = 0;

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

// Iterator
template <class Type>
void LinkedList<Type>::Iterator::insert(const Type& val){
    // if inserting at the end need to update back
    Node<Type>* n = new Node<Type>(val);

    // list is empty
    if(current_node == nullptr){
        front = current_node;
    }

    // revise links
    n->next = current_node->next;
    n->prev = current_node;
    if(current_node->next != nullptr)
        current_node->next->prev = n;
    else
        back = n;
    current_node->next = n;

    // advance the iterator to now point at the newly inserted node
    current_node = n;
}

template <class Type>
Type LinkedList<Type>::Iterator::remove(){
    if(current_node == nullptr){
        cerr << "Error: can't remove node from an empty list.\n";
        exit(-1);
    }
    else{
        Node<Type>* ptr = current_node;
        Type val = current_node->item;

        // not deleting the first node so shift current node
        // to the left
        if(ptr->prev != nullptr){
            current_node = ptr->prev;
            current_node->next = ptr->next;
        }

        // TODO update back
        // deleting the first node 
        else{
            // shift RIGHT
            // deleting from the front but there are stil other nodes
            if(ptr->next != nullptr){
                current_node = ptr->next;
                current_node->prev = nullptr;
            }
            else
                current_node = nullptr;

            front = current_node;
        }
        delete ptr;
        return val;
    }
}