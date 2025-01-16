#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node (int n){
        data=n;
        next=nullptr;
    }
};

class queue {
    node* front;
    node* back;
    public :
    queue (){
        front=nullptr;
        back=nullptr;
    }
    void enque (int value){
        node* n = new node (value);
        if (front==nullptr){
            front=n;
            back=n;
            return;
        }
        back -> next = n;
        back=n;
    }
    void deque (){
        if(isempty ()){
            cout<<"queue empty"<<"\n";
            return;
        }
        node* todelete=front;
        front=front -> next;
        delete todelete;
    }
    bool isempty (){
        if(front==nullptr){
            return 1;
        }
        return 0;
    }
    int peek (){
        if (isempty ()){
            cout<<"peeking empty queue"<<"\n";
        }
        return front -> data;
    }
};

int main (){
    queue q;
    q.enque (2);
    cout<<q.peek ()<<"\n";
    q.enque (3);
    cout<<q.peek ()<<"\n";
    q.deque ();
    cout<<q.peek ()<<"\n";
}