#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    node* previous;
    int data;
    node(int value){
        data=value;
        next=NULL;
        previous=nullptr;
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
    newnode->previous=head;
}

node* insertathead(node* head, int value){
    node* newnode= new node(value);
    newnode->next=head;
    head->previous=newnode;
    return newnode;
}

node* reverse(node* head){
    node* temp=head->next;
    head->next=head->previous;
    head->previous=temp;

    if(head->previous==nullptr)return head;
    node* lastnode=reverse(head->previous);
    return lastnode;
}

void display(node* head){
    int limit=0;
    while(head!=NULL && limit<100){
        cout<<head->data<<"->";
        head=head->next;
        limit++;
    }
    cout<<"null\n";
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
    head=insertathead(head, 0);
    head=reverse(head);
    display(head);
}