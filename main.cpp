#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
    Tree<int> *farbol = new Tree<int>;
    Tree<int> *farbol1 = new Tree<int>;
    farbol->insert(5);
    farbol->insert(3);
    farbol->insert(4);
    farbol->insert(2);
    farbol->insert(7);
    farbol->insert(9);
    //farbol->insert(8);
    farbol->insert(6);
    //farbol->insert(10);
    //farbol->insert(11);
    farbol1->insert(5);
    farbol1->insert(3);
    farbol1->insert(4);
    farbol1->insert(2);    
    farbol1->insert(7);
    farbol1->insert(9);
    //farbol->insert(8);
    farbol1->insert(6);

    cout<<"Imprimiendo arbol1"<<endl;
    farbol1->printtree();

    cout<<"Imprimiendo arbol original"<<endl;
    farbol->printtree();
    //cout<<(farbol->findmin(farbol->root))->key<<endl;
    //cout<<(farbol->findmax(farbol->root))->key<<endl;
    cout<<"1 si los arboles son iguales,0 si no lo son: "<<farbol->checksametree(farbol1->root)<<endl;
    //
   
    farbol->pret_tr();farbol->int_tr();farbol->post_tr(); 
    farbol->countNodes();
    cout<<"Altura:"<<farbol->hight()<<endl;
    cout<<"El ancestro de "<<(farbol->root->right->right)->key<<" es "<<(farbol->ancestor((farbol->root->right)->right))->key<<endl;
 
   // farbol->deleteNode(2);
    //farbol->deleteNode(5);
    farbol->countNodes();
  
    cout<<"1 si es ABS,0 si no lo es: "<<farbol->BSTvalidate()<<endl;
    cout<<"1 si es Completo,0 si no lo es: "<<farbol->validateComplete()<<endl;
    cout<<"1 si es AVL,0 si no lo es: "<<farbol->checkAVL()<<endl;
    farbol->clear();
    delete farbol;
    delete farbol1;
    return 0;
}