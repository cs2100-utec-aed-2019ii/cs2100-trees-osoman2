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
        insert(element,root);   
    }
    void deleteNode(const T& element){
        deleteNode(element,root);
    }
    //minnode    
    Node<T>* findmin(Node<T>*aux){
        if(aux){
          while( aux->left) {
            aux = aux->left;
          }
          return aux;
        }
    }
    Node<T>* findmax(Node<T>*aux){
      if(aux){
          while( aux->right) {
            aux = aux->right;
          }
          return aux;
        }
    }

    bool verificar(T valor){
        
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

    //sobrecargas

    void insert(const T &Element, Node<T>*&nodo ) {
    if (nodo ==nullptr){
        nodo = new Node<T>(Element);
    } else if ( Element < nodo->key ) {
          insert( Element, nodo->left );
    } else if ( Element > nodo->key ) {
          insert( Element, nodo->right );
      } 
    }

    void deleteNode(const T &Element, Node<T>*&nodo){
       if (nodo ==nullptr){
        std::cout<<"El arbol esta vacio"<<std::endl;
        return;
      }
      else{
        if ( Element < nodo->key ) {
          deleteNode( Element, nodo->left );
       } else if ( Element > nodo->key ) {
          deleteNode( Element, nodo->right );
        }
      else if(nodo->left!=nullptr && nodo->right!= nullptr){
          nodo->set_element(findmin(nodo->right)->key);
          delete(nodo->key, nodo->right);
      }
      else{
          Node<T>* oldnodo = nodo;
            nodo = (nodo->left!=nullptr) ? nodo->left : nodo->right;
            delete oldnodo;
        }
      }
    }


};


#endif