#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int value){
        data = value;
        next=NULL;
    }
};

void addtotail(node* &head, int value){
    node* newnode=new node(value);
    if (head==NULL){
        head=newnode;
        return;
    }
    node* temp=head;
    while (temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newnode;
};

void deletion(node* head, int index){
    if (head->next==NULL){
        head=NULL;
        return;
    }
    node* temp=head;
    for (int i=0;i<index-1;i++){
        if (temp->next->next==NULL){
            cout<<"index doesn't exist\n";
            return;
        }
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"null\n";
}

int main(){
    node* head = new node(2);
    addtotail(head, 3);
    display(head);
    deletion(head, 1);
    display(head);
}