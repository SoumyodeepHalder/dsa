#include <iostream>

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert_at_tail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)temp=temp->next;
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        std::cout<<temp->data<<"->";
        temp=temp->next;
    }
    std::cout<<"null"<<'\n';
}
void insert_at_head(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}
int main(){
    node* head=NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_head(head, 4);
    display(head);
}