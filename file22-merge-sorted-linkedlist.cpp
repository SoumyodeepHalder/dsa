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

node* mergesortedlist(node* head, node* secondhead){
    bool isheadlonger=findlength(head)>findlength(secondhead);
    node* big;
    node* sml;
    node* newsml;
    if(isheadlonger){
        big=head;
        sml=secondhead;
    }
    else{
        big = secondhead;
        sml=head;
    }
    while(big!=nullptr){
        if(big->data>sml->data){
            newsml=sml->next;
            sml->next=big;
            big=sml;
            sml=newsml;
            if(isheadlonger)head=big;
            else secondhead=big;
            continue;
        }
        if(big->next->data>sml->data){
            newsml=sml->next;
            sml->next=big->next;
            big->next=sml;
            sml=newsml;
        }
        if(sml==nullptr)break;
        big=big->next;
    }
    if (isheadlonger)return head;
    else return secondhead;
}

int main(){
    node* head = new node(4);
    addtotail(head, 5);
    addtotail(head, 7);
    addtotail(head, 9);
    addtotail(head, 10);
    node* secondhead=new node(2);
    addtotail(secondhead, 3);
    addtotail(secondhead, 6);
    addtotail(secondhead, 8);
    display(head);
    display(secondhead);
    node* sorted=mergesortedlist(head, secondhead);
    display(sorted);
}