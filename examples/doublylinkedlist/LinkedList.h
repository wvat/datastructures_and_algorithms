#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// forward declaration
template <class Type>
class LinkedList;

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
    friend ostream& operator<<(ostream &os, LinkedList& ll){
        Node<Type>* ptr = 0;
        os << "Linked list contents:\n";
        for(ptr=ll.front; ptr; ptr=ptr->next)
            os << ptr->item << " ";
        os << endl;
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

    class Iterator{
    public:
        Iterator() : current_node(front) {}
        Iterator(const Node<Type>* node) : current_node(node) {}

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

        // Postfix increment
        Iterator operator--(int i)
        {
            // TODO use i for variable sized increments
            Iterator temp = *this;
            --*this;
            return temp;
        }

        /*void insert(const Type& val){
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

        Type remove(){
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
        }*/

    private:
        Node<Type>* current_node;
    };

private:
    static Node<Type>* front;
    Node<Type>* back;
};

#endif
