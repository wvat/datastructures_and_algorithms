#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// forward declaration
template <class Type>
class LinkedList<Type>;

template <class Type>
class Node{
public:
    Node(const Type&);
    Type item;
    friend class LinkedList<Type>;
    friend ostream& operator<<(ostream &os, Node& n){
        os << n->item;
        return os;
    }

private:
    Node* next;
    Node* prev;
};

template <class Type>
class LinkedList<Type>{
public:
    LinkedList();
    ~LinkedList();
    void add(const Type&);
    void remove();
    bool is_empty();
    friend class Node<Type>;
    friend ostream& operator<<(ostream &os, LinkedList& ll){
        os << "placeholder" << endl;
        return os;
    }
private:
    Node<Type>* front;
    Node<Type>* back;
};

template <class Type>
class Iterator<Type>{
public:
    friend class LinkedList<Type>;
    friend class Node<Type>;
};

#endif
