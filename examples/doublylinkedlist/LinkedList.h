#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// forward declaration
template <class Type>
class LinkedList;

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
class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    void add(const Type&);
    Type remove();
    bool is_empty();
    friend class Node<Type>;
    friend ostream& operator<<(ostream &os, LinkedList& ll){
        Node<Type>* ptr = 0;
        os << "Linked list contents:\n";
        for(ptr=ll.front; ptr; ptr=ptr->next)
            os << ptr->item << " ";
        os << endl;
        return os;
    }
private:
    Node<Type>* front;
    Node<Type>* back;
};

template <class Type>
class Iterator{
public:
    friend class LinkedList<Type>;
    friend class Node<Type>;

    // operator overloads
    // ++ and --
    // dereference
    // assignment
    // comparison
};

#endif
