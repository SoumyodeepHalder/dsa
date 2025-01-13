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

node* reverse(node* head){
    node* prev=NULL;
    node* nextptr;
    while(head!=NULL){
        nextptr=head->next;
        head->next=prev;
        prev=head;
        head=nextptr;
        // display(head);
    }
    return prev;
}

int main(){
    node* head = new node(1);
    addtotail(head, 2);
    addtotail(head, 3);
    addtotail(head, 4);
    addtotail(head, 5);
    display(head);
    head=reverse(head);
    display(head);
}