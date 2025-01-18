#include <iostream>
using namespace std;

class node {
    public :
    int data;
    node* left;
    node* right;
    node (int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void binarytreetraversal (node* tree, int order){
    if ( tree == nullptr ) return;
    if (order==1)
    cout<<tree -> data<<" ";
    binarytreetraversal (tree -> left, order);
    if (order==2)
    cout<<tree -> data<<" ";
    binarytreetraversal (tree -> right, order);
    if (order==3)
    cout<<tree -> data<<" ";
}

int main(){
    node* tree= new node (1);
    tree -> left = new node (2);
    tree -> right = new node (3);

    node* leftnode= tree -> left;
    leftnode -> left = new node (4);
    leftnode -> right = new node (5);

    node* rightnode = tree -> right;
    rightnode -> left = new node (6);
    rightnode -> right = new node (7);
    binarytreetraversal (tree, 2);
}