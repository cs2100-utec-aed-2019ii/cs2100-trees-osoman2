#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>

template <typename T>

class Tree
{

public:
    Node<T> *root;

    Tree(void):root(nullptr) {
    }

    void insert(const T& element){ 
        Tree<T>*aux = new Tree<T>;
        std::cout<<root<<std::endl<<aux<<std::endl;
        if (root)
        {   
            if(element < root-> get_element()){
                aux->root=root->left;
                aux->insert(element);}

            else if(element>root->get_element()){
                aux->root= root->right;
                aux->insert(element);} 
        }
        else if (root==nullptr)
        {  
            Node<T> *nuevo = new Node<T>(element);
            root = nuevo;
            delete aux;
        }    
    }

    bool verificar(T valor){
        
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