#include "LinkedList.h"

template <class Type>
Node<Type>(const Type& val){
    item = val;
    next = prev = 0;
}


template <class Type>
LinkedList<Type>(){
    front = back = 0;
}

template <class Type>
~LinkedList<Type>(){
    while (!is_empty())
        remove();
}

template <class Type>
void LinkedList<Type>::add(const Type& val){

}

template <class Type>
Type LinkedList<Type>::remove(){

}

template <class Type>
bool LinkedList<Type>::is_empty(){

}