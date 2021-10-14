#ifndef STACK_H
#define STACK_H

// forward declaration
template<class Type>
class Stack;

template<class Type>
class StackItem{
public:
    friend class Stack<Type>;
    StackItem(Type&);
private:
    Type item;
    StackItem* next;
};

template<class Type>
class Stack{
public:
    Stack();
    ~Stack();
    void push(Type&);
    Type pop();
    bool is_empty();
    Type peek();

private:
    StackItem* front;
};

#endif