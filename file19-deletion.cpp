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

void display(node* head){
    int limit=0;
    while(head!=NULL && limit<100){
        cout<<head->data<<"->";
        head=head->next;
        limit++;
    }
    cout<<"null\n";
}

node* deletion(node* head, int key){
    node* temp=head;
    while(temp->data!=key){
        temp=temp->next;
        if (temp==nullptr)return head;
    }
    if(temp->next!=nullptr)temp->next->previous=temp->previous;
    if(temp->previous!=nullptr)temp->previous->next=temp->next;
    else{
        head=head->next;
        delete temp;
        return head;
    }
    delete temp;
    return head;
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
    head=deletion(head, 1);
    display(head);
}