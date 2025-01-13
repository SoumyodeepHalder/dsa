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
    int limit=0;
    while(head!=NULL && limit<15){
        cout<<head->data<<"->";
        head=head->next;
        limit++;
    }
    cout<<"null\n";
}

node* searchdata(node* head, int k){
    while(head!=NULL){
        if(head->data==k)return head;
        else head=head->next;
    }
    return head;
}

bool detectcycle(node* head){
    node* fastptr=head;
    int i=0;
    while(i<100 && fastptr!=NULL && fastptr->next!=NULL){
        head=head->next;
        fastptr=fastptr->next->next;
        if(head==fastptr)return true;
    }
    return false;
}
void removecycle(node* head){
    if (!detectcycle(head))return;
    node* slow=head;
    node* fastptr=head;
    int i=0;
    while(i<100 && fastptr!=NULL && fastptr->next!=NULL){
        slow=slow->next;
        fastptr=fastptr->next->next;
        if(slow==fastptr)break;
    }
    fastptr=head;
    while(slow->next!=fastptr->next){
        slow=slow->next;
        fastptr=fastptr->next;
    }
    slow->next=nullptr;
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
    searchdata(head, 9)->next=searchdata(head, 4); //creating cycle
    cout<<"cycle detected: "<<detectcycle(head)<<"\n";
    removecycle(head);
    display(head);
}