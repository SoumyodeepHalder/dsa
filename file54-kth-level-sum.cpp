#include <iostream>
#include <queue>
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

node* buildbintree (int* preorder, int* &p, int* inorder, int start, int end){
    int curr=0;
    for (int i=start; i <= end; i++){
        if (inorder[i]==preorder[*p])curr=i;
    }
    node* head=new node (preorder[*p]);
    *p+=1;
    if (curr > start)head -> left = buildbintree (preorder, p, inorder, start, curr-1);
    if (curr < end)head -> right = buildbintree (preorder, p,inorder, curr+1, end);
    return head;
}

void kthlevelsum (node* tree, int* result, int k){
    queue <node* > q;
    q.push (tree);
    q.push (nullptr);
    result[0]=tree -> data;
    for (int i=1;i <= k; i++){
        int sum=0;
        while (q.front ()!= nullptr){
            node* curr= q.front ();
            q.pop ();
            if (curr -> left!=nullptr){
                q.push (curr -> left);
                sum+=curr ->left -> data;
            }
            if (curr -> right!=nullptr){
                q.push (curr -> right);
                sum+= curr -> right -> data;
            }
        }
        q.push (q.front ());
        q.pop ();
        result[i]=sum;
    }
}

int main(){
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    int size=sizeof (preorder)/sizeof (preorder[0]);
    int index=0;
    int* p = &index;
    node* tree=buildbintree (preorder, p, inorder, 0, size-1);
    // binarytreeprint (result, 1);
    int levels=2;
    int result[levels+1];
    kthlevelsum (tree, result, levels);
    for (int i=0;i < 3;i++){
        cout<<result[i]<<" ";
    }
}