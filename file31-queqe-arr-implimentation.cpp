#include <iostream>
#include <stack>
using namespace std;
#define n 10

class queue {
    int* arr;
    int front;
    int back;
    public:
    queue (){
        arr=new int[n];
        front=0;
        back=-1;
    }
    bool isempty (){
        return (front > back);
    }
    bool isfull (){
        return back==n-1;
    }
    void enque (int x){
        if (isfull ()){
            return;
        }
        back++;
        arr[back]=x;
    }
    void deque (){
        if (isempty ()){
            return;
        }
        front++;
    }

    int peek (){
        return arr[front];
    }
    
};

int main (){
    queue q;
    q.enque (2);
    q.enque (3);
    q.enque (4);
    cout<<q.peek ()<<"\n";
    q.deque ();
    cout<<q.peek ()<<"\n";
}