#include <iostream>
#include <deque>
using namespace std;

void printdeque (deque <int > q){
    for (auto x : q){
        cout<<x<<"\n";
    }
}

int main(){
    // int arr[]={1,2,3,4};
    deque <int > q;
    q.push_back (1);
    q.push_back (2);
    q.push_back (3);
    q.push_front (4);
    printdeque (q);
}