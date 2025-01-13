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

void addtotail(node* &head, int value){
    node* newnode = new node(value);
    if(head==nullptr){
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->next!=nullptr)temp=temp->next;
    temp->next=newnode;
    return;
}

node* addlisttotail(node* head, node* secondhead){
    node* temp=head;
    while(temp->next!=nullptr)temp=temp->next;
    temp->next=secondhead;
    return head;
}

void display(node* head){
    int count =0;
    cout<<"printing list:\n";
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"end of list\n";
}

node* mergesortedlist(node* head, node* secondhead){
    node* merged=nullptr;
    while(1){
        if(head==nullptr)return addlisttotail(merged, secondhead);
        else if(secondhead==nullptr)return addlisttotail(merged, head);
        if(head->data>secondhead->data){
            addtotail(merged, secondhead->data);
            secondhead=secondhead->next;
        }
        else{
            addtotail(merged, head->data);
            head=head->next;
        }
    }
};

int main(){
    node* head=new node(1);
    addtotail(head, 2);
    addtotail(head, 4);
    display(head);
    node* secondhead=new node(3);
    addtotail(secondhead, 5);
    display(head);
    display(secondhead);
    node* merged=mergesortedlist(head, secondhead);
    display(merged);
}