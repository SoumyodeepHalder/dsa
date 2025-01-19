#include <iostream>
using namespace std;

class node {
    public :
    node* left;
    node* right;
    node (int val){
        left= nullptr;
        right = nullptr;
    }
    node* buildrecursive (int* preorder, int p, int* inorder, int left, int right){
        node* head=new node (preorder[0]);
        int curr=0;
        for (int i=0;i <= right ; i++){
            if (preorder [0]==inorder [i]){
                curr=i;
                break;
            }
        }
        p+=1;
        if (curr > 0)head -> left=buildrecursive (preorder, p, inorder, 0, curr-1);
        if (curr < right)head -> right = buildrecursive (preorder, p, inorder, curr+1, right);
        return head;
    }
    node* build (int* preorder, int* inorder, int size){
        node* head=new node (preorder[0]);
        static int p=0;
        int curr=0;
        for (int i=0;i < size ; i++){
            if (preorder [0]==inorder [i]){
                curr=i;
                break;
            }
        }
        p+=1;
        if (curr > 0)head -> left=buildrecursive (preorder, p, inorder, 0, curr-1);
        if (curr < size)head -> right = buildrecursive (preorder, p, inorder, curr+1, size-1);
        return head;
    }
};

int main(){
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
}