// temp = head; means temp will point at location where head is pointing.
// head = head-> next; means head will point at the location where it's next is pointing.

#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int value){
        data = value;
        next = NULL;
    }
};

node* findthelastnode(node* temp){
    while (temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

bool createfirstnodeifheadisnull(node* &head, node* newnode){
    if (head==NULL){
        head=newnode;
        return true;
    }
    return false;
}

bool solveedgecases(node* &head, node* newnode){
    if (createfirstnodeifheadisnull(head, newnode)) return true;
    return false;
}

void insertattail(node* &head, int value){
    node* newnode = new node(value); //creating a new node
    if (solveedgecases(head, newnode)) return;
    node* temp = head;
    temp = findthelastnode(temp);
    temp->next = newnode;
};

void insertathead(node* &head, int value){
    node* newnode = new node(value);
    newnode->next=head->next;
    head->next=newnode;
    int temp = head->data;
    head=newnode;
}

void displaylinkedlist(node* temp){
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"null"<<"\n";
}

int main(){
    node* head=NULL;
    insertattail(head, 1);
    insertattail(head, 3);
    insertattail(head, 5);
    displaylinkedlist(head);
    cout<<&head<<','<<head<<','<<','<<head->next<<'\n';
    head=head->next;
    cout<<&head<<','<<head<<','<<','<<head->next;
}