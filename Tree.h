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
          std::cout<<"El nodo eliminado es: "<<element<<std::endl;
         deleteNode(root,element);
    }

    bool validateComplete(){
        return validateComplete(root,0,countNodes(root));
    }
    bool checksametree(Node<T>* tree){
      return checksametree(root,tree);
    }

//---------------validacion de arboles iguales definicion
    bool checksametree(Node<T>* nodo1,Node<T>* nodo2){
      if (nodo1== nodo2)  return true;
      if ((nodo1 == nullptr) || (nodo2 == nullptr))  return false;

      return ((nodo1->key == nodo2->key) && checksametree (nodo1->left,nodo2->left )&& checksametree(nodo1->right, nodo2->right));
    }
//----------------------------


//-------------Avl
    bool checkAVL(){
        return checkAVL(root);
    }
    bool checkAVL(Node<T>*nodo){
      if (nodo == nullptr) 
        return true;  
      else if (hight(nodo,0)-hight(nodo->left,0)>1||hight(nodo,0)-hight(nodo->right,0)>1) 
        return false; 
  
      return (checkAVL(nodo->left)   && checkAVL(nodo->right));
    }

//------------------------------
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


// validacion completa ----------
        //contar nodos
    void countNodes() 
    { std::cout<<"La cantidad de nodos es: "<<countNodes(root)<<std::endl;
    }
    unsigned int countNodes(Node<T>* nodo) 
    { 
    if (nodo == nullptr) 
        return 0; 
    return 1 + countNodes(nodo->left) + countNodes(nodo->right); 
    }
        //------------- 
    
    bool validateComplete (Node<T>* nodo, unsigned int index,unsigned int number_nodes){
    if (nodo == nullptr) 
        return true;  
    if (index >= number_nodes) 
        return false; 
  
    return (validateComplete(nodo->left, 2*index + 1, number_nodes) && validateComplete(nodo->right, 2*index + 2, number_nodes)); 
    } 

//-----------------


    //validaciónBST--------------
    bool BSTvalidate(){
      return BSTvalidate(root,findmin(root)->key,findmax(root)->key);
    }
    bool BSTvalidate(Node<T> *node, const T& minKey,const T&maxKey) {
    if (node == nullptr) return true;
    if (node->key < minKey || node->key > maxKey) return false;
    
    return BSTvalidate(node->left, minKey, node->key-1) && BSTvalidate(node->right, node->key+1, maxKey);
    }

    //---------------------------
    
    void clear(void){
      std::cout<<"Eliminación de arbol por nodos: ";
      clear(root);
      std::cout<<std::endl;
    }

    Node<T>* ancestor(Node<T>*nodo){
      return ancestor(root,nodo);
    }
    //definición
    Node<T>* ancestor(Node<T>* nodo,Node<T>*buscado){
        if(nodo&&buscado){
          if(buscado->key<nodo->key){
            if(buscado->key==nodo->left->key ) return nodo;
            else return ancestor(nodo->left,buscado);
          }
          else if(buscado->key>nodo->key){
            if (buscado->key== nodo->right->key) return nodo;
            else return ancestor(nodo->right,buscado);
          }
        }
        else return nullptr;
    }

    void printtree(){
      printtree(root,0);
    }
    void printtree(Node<T>*nodo,int cont){
        if (nodo ==nullptr)return;
        else{
        printtree(nodo->right,cont+1);
        for(int i = 0;i<cont;i++){
          std::cout<<"  ";
          }
        }
        std::cout<<nodo->key<<std::endl;
        printtree(nodo->left,cont+1);
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

//-----------------
void swap(Node<T>*a,Node<T>*b){
  auto temp = a->key; 
  a->set_element(b->key);
  b->set_element(temp);
}
void deleteNode(Node<T>* nodo, const T& key) 
{ if(nodo ==nullptr)return;

  else{
    if(key<nodo->key){
      deleteNode(nodo->left,key);
    }
    else if(key>nodo->key){
      deleteNode(nodo->right,key);
    }
    else if(key==nodo->key){
      if( (nodo->right==nullptr&&nodo->left) ||(nodo->right&&nodo->left) ){

          Node<T>* temp =findmax(nodo->left); 
          Node<T>* aux = ancestor(temp);
          swap(nodo,findmax(nodo->left));
          if(aux->left == temp) aux->left = nullptr;
          else if(aux->right == temp)aux->right = nullptr;
          delete temp;return;
      }

      else if(nodo->left==nullptr&&nodo->right ){
          Node<T>* temp =findmin(nodo->right);
          Node<T>* aux = ancestor(temp);
          swap(nodo,findmin(nodo->right));
          if(aux->left == temp) aux->left = nullptr;
          else if(aux->right == temp)aux->right = nullptr;
          delete temp;return;
      }
      else{
      Node<T>* temp =nodo; 
      Node<T>* aux = ancestor(temp);
      if(aux->left == temp) aux->left = nullptr;
      else if(aux->right == temp)aux->right = nullptr;
      delete temp;return;
      }
    }
      
      
  }
      
}


//---------------
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