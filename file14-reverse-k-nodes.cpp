#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    int data;
    node(int value){
        data=value;
        next=NULL;
    }
};

void addtotail(node* head, int value){
    node* newnode=new node(value);
    if (head==NULL){
        head=newnode;
        return;
    }
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=newnode;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"null\n";
}

node* reverse(node* head, int k){
    if(k==1)return head;
    node* lastnode=reverse(head->next, k-1);
    head->next->next=head;
    head->next=NULL;
    return lastnode;
}

node* reversek(node* head, int k){
    if(head==NULL)return head;
    node* nextptr = head;
    node* lastnode;
    for(int i=0;i<k;i++){
        nextptr=nextptr->next;
    }
    display(nextptr);
    nextptr=reversek(nextptr, k);
    lastnode=reverse(head, k);
    head->next=nextptr;
    return lastnode;
}

int main(){
    node* head = new node(1);
    addtotail(head, 2);
    addtotail(head, 3);
    addtotail(head, 4);
    addtotail(head, 5);
    addtotail(head, 6);
    addtotail(head, 7);
    addtotail(head, 8);
    addtotail(head, 9);
    display(head);
    head=reversek(head,3);
    display(head);
}