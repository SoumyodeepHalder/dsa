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
int findtreedepth (node* tree){
    int count=0;
    while (tree!=nullptr){
        count++;
        tree=tree -> left;
    }
    return count;
}
void visualizetree (node* tree){
    queue <node* > q;
    q.push (tree);
    q.push (nullptr);
    int depth=findtreedepth (tree);
    for (int i=0;i < depth; i++){
        while (q.front ()!=nullptr){
            node* curr=q.front ();
            q.pop ();
            cout<<curr -> data<<" ";
            if (curr -> left != nullptr){
                q.push (curr -> left);
            }
            if (curr -> right != nullptr){
                q.push (curr -> right );
            }
        }
        q.push (q.front ());
        q.pop ();
        cout<<"\n";
    }
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
int countallnodes (node* tree){
    if (tree== nullptr)return 0;
    return countallnodes (tree -> left)+countallnodes (tree -> right)+1;
}
int sumallnodes (node* tree){
    if (tree==nullptr)return 0;
    return (tree -> data)+sumallnodes (tree -> left)+sumallnodes (tree -> right);
}
int main(){
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    int size=sizeof (preorder)/sizeof (preorder[0]);
    int index=0;
    int* p = &index;
    node* result=buildbintree (preorder, p, inorder, 0, size-1);
    visualizetree (result);
    cout<<countallnodes (result)<<"\n";
    cout<<sumallnodes (result)<<"\n";
}