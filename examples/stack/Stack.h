#ifndef STACK_H
#define STACK_H

// forward declaration
template<class Type>
class Stack;

template<class Type>
class StackItem{
public:
    friend class Stack<Type>;
    StackItem(const Type&);

    friend ostream& operator<<(ostream& os, StackItem<Type>& si){
        os << si.item;
        return os;
    }
private:
    Type item;
    StackItem* next;
};

template<class Type>
class Stack{
public:
    Stack();
    ~Stack();
    void push(const Type&);
    Type pop();
    bool is_empty();
    Type peek();

    friend ostream& operator<<(ostream& os, Stack<Type>& s){
        StackItem<Type>* ptr;
        
        os << "Stack Contents:\n";
        for(ptr=s.front; ptr; ptr=ptr->next)
            os << *ptr << " ";
        os << endl;
        return os;
    }

private:
    StackItem<Type>* front;
};

#endif