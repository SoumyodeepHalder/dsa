// don't have to create new nodes to merge two sorted linked lists
// add existing nodes to the new list

#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int value){
        data=value;
        next=nullptr;
    }
};

void display(node* head){
    int count =0;
    node* temp=head;
    cout<<"printing list:\n";
    while(temp->next!=head && count<100){
        cout<<temp->data<<"->";
        temp=temp->next;
        count++;
    }
    cout<<temp->data<<"->"<<head->data<<"\n";
}

void addtotail(node* &head, int value){
    node* newnode = new node(value);
    if(head==nullptr){
        head=newnode;
        head->next=head;
        return;
    }
    node* temp=head;
    while(temp->next!=head)temp=temp->next;
    temp->next=newnode;
    newnode->next=head;
    return;
}



int main(){
    node* head=nullptr;
    addtotail(head, 2);
    addtotail(head, 4);
    addtotail(head, 5);
    addtotail(head, 6);
    addtotail(head, 7);
    display(head);
}