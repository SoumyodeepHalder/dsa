#include <iostream>
#include <stack>
using namespace std;
#define max 10

class myqueue {
    public :
    int front;
    int back;
    stack <int> st;
    stack <int> sta;
    myqueue (){
        front=-1;
        back=-1;
    }
    bool isempty (){
        return (front ==-1 && back==-1);
    }
    bool isfull (){
        return (front+back+2 == max);
    }
    void enque (int value){
        if (isfull ()){
            cout<<"full"<<"\n";
            return;
        }
        back++;
        st.push (value);
    }
    void deque (){
        if (isempty()){
            cout<<"empty"<<"\n";
            return;
        }
        if (sta.empty ()){
            while (!st.empty ()){
                front++;
                sta.push(st.top ());
                back--;
                st.pop ();
            }
        }
        front--;
        sta.pop ();
    }
    int peek (){
        if (sta.empty ()){
            while (!st.empty ()){
                front++;
                sta.push(st.top ());
                back--;
                st.pop ();
            }
        }
        return sta.top ();
    }  
};

int main (){
    myqueue q;
    q.enque (2);
    cout<<q.peek ()<<"\n";
    q.enque (3);
    cout<<q.peek ()<<"\n";
    q.deque ();
    cout<<q.peek ()<<"\n";
}