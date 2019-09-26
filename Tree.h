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

    unsigned int hight(void){
      return hight(root,0);
    }
    unsigned int hight(Node<T> *nodo,unsigned int tam){
      if(nodo == nullptr){
        return tam;
      }
      else{
        unsigned int L= hight(nodo->left,tam);
        unsigned int R= hight(nodo->right,tam);
        tam = L<R?R:L;
        return tam+1;
      }
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
    
    void clear(void){
      std::cout<<"Eliminación de nodos: ";
      clear(root);
      std::cout<<std::endl;
    }

    Node<T>* ancestor(Node<T>*nodo){
      return ancestor(root,nodo);
    }
    
    
    
    
    //definición
    Node<T>* ancestor(Node<T>* nodo,Node<T>*buscado){
        if(nodo){
          if(buscado->key<nodo->key){
            if(buscado->key==nodo->left->key ||buscado->key== nodo->right->key) return nodo;
            else return ancestor(nodo->left,buscado);
          }
          else if(buscado->key>nodo->key){
            if (buscado->key==nodo->left->key ||buscado->key== nodo->right->key) return nodo;
            else return ancestor(nodo->right,buscado);
          }
        }
        else return nullptr;
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

  //definiendo clear

    void clear(Node<T>*&nodo){
      if (nodo == NULL) return;  
  
     clear(nodo->left);  
     clear(nodo->right);  
     std::cout << "\n Nodo eliminado: " << nodo->key;  
      free(nodo); 
    }

};


#endif