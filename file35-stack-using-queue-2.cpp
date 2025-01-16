#include <iostream>
#include <queue>
using namespace std;

class mystack {
    queue <int > q;
    queue <int > qu;
    int n=0;
    public :
    void push (int value){
        n++;
        q.push (value);
    }
    void pop (){
        if (q.empty ()){
            cout<<"empty"<<"\n";
        }
        for (int i =0;i < n-1;i++){
            qu.push (q.front ());
            q.pop ();
        }
        q.pop ();
        n--;
        queue <int > temp=q;
        q=qu;
        qu=temp;
    }
    int top (){
        if (q.empty ()){
            cout<<"empty"<<"\n";
            return -1;
        }
        for (int i =0;i < n-1;i++){
            qu.push (q.front ());
            q.pop ();
        }
        int ans=q.front ();
        qu.push (q.front ());
        q.pop ();
        queue <int > temp=q;
        q=qu;
        qu=temp;
        return ans;
    }
};

int main(){
    mystack stk;
    stk.push (2);
    cout<<stk.top ()<<"\n";
    stk.push (3);
    cout<<stk.top ()<<"\n";
    stk.push (4);
    cout<<stk.top ()<<"\n";
    stk.pop ();
    cout<<stk.top ()<<"\n";
    stk.pop ();
    cout<<stk.top ()<<"\n";
}