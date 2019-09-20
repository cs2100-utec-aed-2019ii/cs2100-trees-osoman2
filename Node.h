#ifndef NODE_H
#define NODE_H



template <typename T>

class Node
{

public:
    T key;
    Node<T> *left,*right;
    //implementar una lista en hojas
    Node(T key){
        this->key = key;
        this->left = this->right = nullptr;
    }
    ~Node();
    void set_element(const T& element){
        key = element;
    }
    T get_element(){
        return Node<T>::key;
    }
};


#endif