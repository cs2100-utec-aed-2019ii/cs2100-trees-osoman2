#include <iostream>
#include "./Tree.h"

using namespace std;

int main(){
    Tree<int> *farbol = new Tree<int>;
    farbol->insert(3);
    farbol->insert(4);
    farbol->insert(2);
    cout<<farbol->root->key<<endl;
    cout<<farbol->root->left->key <<endl;
    cout<<farbol->root->right->key<<endl;

    delete farbol;

    return 0;
}