#include<iostream>
using namespace std;
#define stacklength 10

class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr = new int[stacklength];
        top=-1;
    };
    void push(int x){
        if(top==stacklength-1){
            cout<<"stack overflow\n";
            return;
        };
        top++;
        arr[top]=x;
    };
    void pop(){
        if(top==-1){
            cout<<"no elements in stack\n";
            return;
        }
        top--;
    };
    int viewtop(){
        if(top==-1){
            cout<<"no elements in stack\n";
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.viewtop()<<"\n";
    st.pop();
    cout <<st.viewtop ()<<"\n";
    cout<<st.empty ()<<"\n";
    string s="hey how";
}