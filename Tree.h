#ifndef TREE_H
#define TREE_H
#include "Node.h"


template <typename T>

class Tree:public Node<T>
{

public:
    Node<T> *root;

    Tree(void):root(nullptr){
    }

    void insertNode(Node<T>*element){

    }

    void deleteNode(Node<T>*element){
        
    }

    unsigned int height(Tree<T>&){

    }

    void clear(void){

    }


    void int_tr(void){

    }    
    void pret_tr(void){

    }    
    void post_tr(void){

    }    

    Node<T>* next_samel(Node<T>* nodo){

    }

    bool complete(Tree&){

    }

    Node<T>* ancestor(Node<T>* nodo){

    }

    void printtree(Tree&){

    }

    bool isbalanced(Tree&){

    }

    bool checkBST(){

    }

    void convertBST(){

    }

    int leafheigh(){

    }
};


#endif