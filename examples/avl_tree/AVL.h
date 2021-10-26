#ifndef AVL
#define AVL

template<class Type>
class Node{
public:
    Node();
private:
    Type item;
    int height;
    Node* parent;
    Node* left_tree;
    Node* right_tree;
};

template<class Type>
class AVL{
public:
    AVL();
    ~AVL();
    bool is_empty();
    int get_height();
    void insert(const Type&);
    Type remove();

private:
    Node<Type>* root;
};

#endif