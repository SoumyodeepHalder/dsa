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

void reverse(node* &head){
    node* temp1=head->next;
    node* temp2=head->next->next;
    head->next=NULL;
    while(temp1!=NULL){
        temp1->next=head;
        head=temp1;
        temp1=temp2;
        if (temp2==NULL);
        else{temp2=temp2->next;}
    }
}

int main(){
    node* head = new node(1);
    addtotail(head, 2);
    addtotail(head, 3);
    addtotail(head, 4);
    addtotail(head, 5);
    display(head);
    reverse(head);
    display(head);
}