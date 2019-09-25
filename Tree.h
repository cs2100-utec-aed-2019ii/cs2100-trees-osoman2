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
    //maxnode
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

    unsigned int hight(){
      return hight(root);
    }
    int hight(Node<T> *nodo){
      if(nodo == nullptr){
        return -1;
      }
      else{
        unsigned int L= hight(nodo->left);
        unsigned int R= hight(nodo->right);
        return (L<R?R:L);
      }
    } 

    void clear(void){

    }


    void int_tr(void){
      std::cout<<"In-order:"<<std::endl;
      inO(root);
      std::cout<<std::endl;
    }    
    void pret_tr(void){
      std::cout<<"Pre-order:"<<std::endl;
      preO(root);
      std::cout<<std::endl;
    }    
    void post_tr(void){
      std::cout<<"Post-order:"<<std::endl;
      postO(root);
      std::cout<<std::endl;
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
        return;
      }
      else{
        if ( Element < nodo->key ) {
          deleteNode( Element,nodo->left );
       }else if ( Element > nodo->key ) {
          deleteNode( Element,nodo->right );
        }
      else if(nodo->left!=nullptr && nodo->right!= nullptr){
          nodo->set_element(findmin(nodo->right)->key);
          deleteNode(nodo->key, nodo->right);
      }
      else{
          Node<T>* oldnodo = nodo;
            nodo = (nodo->left!=nullptr) ? nodo->left :nodo->right;
            delete oldnodo;
        }
      }
    }


  //definicion de recorridos

  void inO(Node<T> *nodo ) const {
    if(nodo) {
        inO(nodo->left);
        std::cout <<nodo->key << " " ;
        inO(nodo->right);
      }
  }

  void preO( Node<T> *nodo ) const {
    if(nodo) {
        std::cout <<nodo->key << " " ;
        preO(nodo->left);
        preO(nodo->right);
      }
    }
  void postO( Node<T> *nodo ) const {
    if(nodo){
    postO(nodo->left);
    postO(nodo->right);
    std::cout << nodo->key << " " ; 
    }
  }

};


#endif