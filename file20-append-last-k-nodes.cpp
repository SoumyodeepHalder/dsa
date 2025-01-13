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

int findlength(node* head){
    int count=0;
    while(head!=nullptr){
        head=head->next;
        count++;
    }
    return count;
}

node* lastknodes(node* head, int k){
    //edge cases
    if(findlength(head)==1)return head;
    if(k>=findlength(head))return head;

    node* newtail = head;
    node* oldtail=head;
    for(int i=0;i<k;i++){
        oldtail=oldtail->next;
    }
    while(oldtail->next!=nullptr){
        oldtail=oldtail->next;
        newtail=newtail->next;
    }
    oldtail->next=head;
    head=newtail->next;
    newtail->next=nullptr;
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
    head=lastknodes(head, 5);
    display(head);
}