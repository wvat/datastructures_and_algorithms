#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// forward declaration
template <class Type>
class LinkedList;

template <class Type>
class Node{
    friend class LinkedList<Type>;
    friend std::ostream& operator<<(std::ostream &os, Node& n){
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
    friend std::ostream& operator<<(std::ostream &os, LinkedList& ll){
        Node<Type>* ptr = 0;
        os << "Linked list contents:\n";
        for(ptr=ll.front; ptr; ptr=ptr->next)
            os << ptr->item << " ";
        os << std::endl;
        return os;
    }
public:
    LinkedList(){
        front = back = 0;
    }
    ~LinkedList();
    void add(const Type&);
    Type remove();
    bool is_empty();

    class Iterator;
    Iterator get_front()
    {
        return Iterator();
    }

    Iterator get_end()
    {
        return Iterator(nullptr);
    }

    class Iterator{
    public:
        Iterator() : current_node(front) {}
        Iterator(Node<Type>* node){
            current_node = node;
        }

        // Prefix increment
        Iterator& operator++()
        {
            current_node = current_node->next;
            return *this;
        }

        // Prefix decrement 
        Iterator& operator--()
        {
            current_node = current_node->prev;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int i)
        {
            // TODO use i for variable sized increments
            Iterator temp = *this;
            ++*this;
            return temp;
        }

        // Postfix decrement
        Iterator operator--(int i)
        {
            // TODO use i for variable sized increments
            Iterator temp = *this;
            --*this;
            return temp;
        }

        // Dereference operator
        Type operator*()
        {
            return current_node->item;
        }

        // Inequality operator
        bool operator!=(const Iterator& i){
            return current_node != i.current_node;
        }

        // Equality operator
        bool operator==(const Iterator& i){
            return current_node == i.current_node;
        }

        void insert(const Type&);
        Type remove();

    private:
        Node<Type>* current_node;
    };

private:
    static Node<Type>* front;
    static Node<Type>* back;
};

#endif
