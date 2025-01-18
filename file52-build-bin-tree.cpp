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

int log2 (int n){
    int count=0;
    while (n!=1){
        n=int (n/2);
        count++;
    }
    return count;
}


void binarytreeprint (node* tree, int order){
    if ( tree == nullptr ) return;
    if (order==1)
    cout<<tree -> data<<" ";
    binarytreeprint (tree -> left, order);
    if (order==2)
    cout<<tree -> data<<" ";
    binarytreeprint (tree -> right, order);
    if (order==3)
    cout<<tree -> data<<" ";
}
node* buildbintree (int *arr, int* &i, int levels){
    if (levels == 0)return nullptr;
    node* head=new node (arr[*i]);
    *i+=1;
    head -> left = buildbintree (arr, i, levels - 1);
    head -> right = buildbintree (arr, i, levels - 1);
    binarytreeprint (head, 1);
    cout<<"\n";
    return head;
}

int main(){
    int arr[]={1,2,4,5,3,6,7};   
    int size=sizeof (arr)/sizeof (arr[0]);
    int levels=log2 (size +1);
    int index=0;
    int* i=&index;
    node* result = buildbintree (arr, i, levels);
    binarytreeprint (result, 1);
}