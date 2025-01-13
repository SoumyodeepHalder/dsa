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

node* searchdata(node* head, int k){
    while(head!=NULL){
        if(head->data==k)return head;
        else head=head->next;
    }
    return head;
}

int findinterseaction(node* head, node* secondhead){
    int length1=findlength(head);
    int length2=findlength(secondhead);
    bool islength1longer=length1>length2;
    if (islength1longer){
        for(int i=0;i<length1-length2;i++){
            head=head->next;
        }
    }
    else{
        for(int i=0;i<length2-length1;i++){
            secondhead=secondhead->next;
        }
    }
    while(head!=secondhead){
        if(head!= nullptr)return -1;
        head=head->next;
        secondhead=secondhead->next;
    }
    return head->data;
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
    node* secondhead=new node(1);
    addtotail(secondhead, 2);
    addtotail(secondhead, 3);
    addtotail(secondhead, 4);
    display(head);
    display(secondhead);
    // searchdata(secondhead, 4)->next=searchdata(head, 7);
    cout<<findinterseaction(head, secondhead);
}