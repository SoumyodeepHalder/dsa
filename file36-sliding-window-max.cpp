#include <iostream>
#include <deque>
#include <array>
#include <vector>
using namespace std;

void printdeque (deque <int > q){
    for (auto x : q){
        cout<<x<<" ";
    }
    cout<<"\n"<<"\n";
}

int maximumslidingwindow (vector <int > arr,int k){
    deque <int > dq;
    for (int i=0;i < k;i++){
        dq.push_back (arr[i]);
    }

    int currentsum=0;
    int maxsum=0;
    for (int i=0;i < k;i++){
        currentsum+=arr[i];
    }
    maxsum=currentsum;
    if (arr.size ()==k){
        return currentsum;
    }

    for (int i=k;i < arr.size ();i++){
        cout<<currentsum<<"\n";
        printdeque (dq);
        currentsum-=dq.front ();
        // cout<<currentsum<<"\n";
        currentsum+=arr[i];
        // cout<<currentsum<<"\n\n";
        dq.pop_front ();
        dq.push_back (arr[i]);
        if (currentsum > maxsum)maxsum=currentsum; 
    }
    return maxsum;
}

int main (){
    vector <int> arr={1,3,-1,-3,5,3,6,7};
    int windowlength=3;
    // cout<<arr.size ()<<"\n";2
    cout<<maximumslidingwindow (arr, windowlength)<<"\n";
}