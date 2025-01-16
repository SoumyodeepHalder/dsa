#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

void slidingwindowmax (int* arr, int sizeofarr,int k){
    deque <int > stk;
    deque <int > ans;
    for (int i=0;i <k;i++){
        while (!stk.empty () &&  arr[i] > stk.back ()){
            stk.pop_back ();
        }
        stk.push_back (arr[i]);
    }
    ans.push_back (stk.front ());
    for (int i=k;i < sizeofarr; i++){
        if (stk.front () == arr[i-k]){
            stk.pop_front ();
        }
        while (!stk.empty () &&  arr[i] > stk.back ()){
            stk.pop_back ();
        }
        stk.push_back (arr[i]);
        ans.push_back (stk.front ());
    }
    for (auto i : ans){
        cout<<i<<"\n";
    }
}

int main(){
    int arr[]={1,3,-1,-3,5,3,6,7};
    int windowsize=3;
    slidingwindowmax (arr, 8, windowsize);
}