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

node* reverse(node* head, node* prevptr, node* nextptr){
    if(head==NULL)return prevptr;
    nextptr=head->next;
    head->next=prevptr;
    prevptr=head;
    head=nextptr;
    reverse(head, prevptr, nextptr);
}

int main(){
    node* head = new node(1);
    addtotail(head, 2);
    addtotail(head, 3);
    addtotail(head, 4);
    addtotail(head, 5);
    display(head);
    head=reverse(head, NULL, head->next);
    display(head);
}