#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
    Tree<int> *farbol = new Tree<int>;
    farbol->insert(5);
    farbol->insert(3);
    farbol->insert(4);
    farbol->insert(2);
    farbol->insert(7);
    farbol->insert(9);
    farbol->insert(8);
    farbol->insert(6);
    farbol->insert(10);
    farbol->insert(11);


    //cout<<(farbol->findmin(farbol->root))->key<<endl;
    //cout<<(farbol->findmax(farbol->root))->key<<endl;

    cout<<farbol->root->key<<endl;
    cout<<farbol->root->left->key <<endl;
    cout<<farbol->root->right->key<<endl;
  
    //
    cout<<farbol->root->key<<endl;
    farbol->pret_tr();farbol->int_tr();farbol->post_tr(); 
    cout<<"Altura:"<<farbol->hight()<<endl;
    
    cout<<"El ancestro de "<<(farbol->ancestor((farbol->root->right)->right))->key<<" es "<<farbol->root->key<<endl;
 
    farbol->deleteNode(2);
    farbol->deleteNode(5);
    farbol->pret_tr();farbol->int_tr();farbol->post_tr();
    cout<<"1 si es ABS,0 si no lo es: "<<farbol->BSTvalidate()<<endl;
    farbol->clear();
    

    delete farbol;

    return 0;
}