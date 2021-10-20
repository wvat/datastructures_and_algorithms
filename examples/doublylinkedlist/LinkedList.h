#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// forward declaration
template <class Type>
class LinkedList;

template <class Type>
class Iterator;

template <class Type>
class Node{
    friend class LinkedList<Type>;
    friend ostream& operator<<(ostream &os, Node& n){
        os << n->item;
        return os;
    }
public:
    Node(const Type&);
    Type item;
private:
    Node* next;
    Node* prev;
};

template <class Type>
class LinkedList{
    friend class Node<Type>;
    friend class Iterator<Type>;
    friend ostream& operator<<(ostream &os, LinkedList& ll){
        Node<Type>* ptr = 0;
        os << "Linked list contents:\n";
        for(ptr=ll.front; ptr; ptr=ptr->next)
            os << ptr->item << " ";
        os << endl;
        return os;
    }
public:
    LinkedList();
    ~LinkedList();
    void add(const Type&);
    Type remove();
    bool is_empty();
private:
    Node<Type>* front;
    Node<Type>* back;
};

template <class Type>
class Iterator{
    friend class LinkedList<Type>;
    friend class Node<Type>;
public:
    Iterator(const LinkedList<Type>&);
    ~Iterator();

    // operator overloads
    // ++ and --
    // Prefix operator
    Iterator<Type>& operator++();
    Iterator<Type>& operator--();

    // Postfix operator
    Iterator<Type> operator++(int);
    Iterator<Type> operator--(int);
    
    // dereference
    // assignment
    // comparison

    void insert(const Type&);
    Type remove();
private:
    LinkedList<Type>* list;
    Node<Type>* current_node;
};

#endif
