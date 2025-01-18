#include <bits/stdc++.h>
using namespace std;

void stock_span (int* arr, int size, int* ans){
    stack <int > decending;
    stack <int > value;
    // int ans[size];
    for (int i=0;i < size; i++){
        int newval=1;
        while (!decending.empty () &&  arr[i] > decending.top ()){
            decending.pop ();
            newval+=value.top ();
            value.pop ();
        }
        decending.push (arr[i]);
        value.push (newval);
        ans[i]=newval;
    }
    // return ans;
}
int main(){
    int arr[]={100, 80, 60, 70, 60, 75, 85};
    int size=sizeof (arr)/sizeof (arr[0]);
    int ans[size];
    stock_span (arr, size, ans);
    for (int i=0;i < size; i++){
        cout<<ans[i]<<" ";
    }
}