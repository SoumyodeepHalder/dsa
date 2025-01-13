#include<iostream>
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

node* gototail(node* head){
    while(head->next!=nullptr)head=head->next;
    return head;
}

node* addtotail(node* head,int n){
    node* newnode=new node(n);
    if(head==nullptr)return newnode;
    node* temp=head;
    temp=gototail(head);
    temp->next=newnode;
    return head;
};

node* addlisttotail(node* head, node* tail){
    node* temp;
    temp=gototail(head);
    temp->next=tail;
    return head;
}

void displaylist(node* head){
    int count=0;
    cout<<"printing list\n";
    while(head!=nullptr && count<100){
        cout<<head->data<<"->";
        head=head->next;
        count++;
    }
    cout<<"end\n";
    return;
}

node* mergesortedlist(node* head, node* secondhead){
    node* mergedlist=nullptr;
    node* ptr1=head;
    node* ptr2=secondhead;
    int count=0;
    while(count<100){
        if(ptr1==nullptr)return addlisttotail(mergedlist, ptr2);
        else if(ptr2==nullptr)return addlisttotail(mergedlist, ptr1);
        if(ptr1->data>ptr2->data){
            mergedlist=addtotail(mergedlist, ptr2->data);
            ptr2=ptr2->next;
        }
        else {
            mergedlist=addtotail(mergedlist, ptr1->data);
            ptr1=ptr1->next;
        }
        count++;
    }
    return mergedlist;
}

int main(){
    node* head=nullptr;
    head=addtotail(head, 3);
    head=addtotail(head,4);
    head=addtotail(head,7);
    node* secondhead=new node(1);
    secondhead=addtotail(secondhead, 2);
    secondhead=addtotail(secondhead, 5);
    displaylist(head);
    displaylist(secondhead);
    node* mergedlist=mergesortedlist(head,secondhead);
    // node* mergedlist=addlisttotail(head, secondhead);
    displaylist(mergedlist);
}