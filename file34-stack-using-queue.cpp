#include <iostream>
#include <queue>
using namespace std;

class mystack {
    queue <int > q;
    queue <int > qu;
    public :

    void push (int value){
        qu.push (value);
        while (!q.empty ()){
            qu.push (q.front ());
            q.pop ();
        }
        queue <int > temp=q;
        q=qu;
        qu=temp;
    }
    void pop (){
        if (q.empty ()){
            cout<<"empty"<<"\n";
            return;
        }
        q.pop ();
    }
    bool empty (){
        return q.empty ();
    }
    int top (){
        return q.front ();
    }
};

int main (){
    mystack stack;
    stack.push (2);
    cout<<stack.top ()<<"\n";
    stack.push (3);
    cout<<stack.top ()<<"\n";
    stack.push (4);
    cout<<stack.top ()<<"\n";
    stack.pop ();
    cout<<stack.top ()<<"\n";
    stack.pop ();
    cout<<stack.top ()<<"\n";
}