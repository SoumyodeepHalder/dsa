#include <iostream>
using namespace std;

int maxconsecutiveones (bool* arr, int size, int k){
    int maxlen=0;
    int zeros=0; 
    int left=0;
    int right=1;
    if (arr[0]==0)zeros=1;
    else zeros=0;
    while (right < size){
        if (zeros <= k){
            maxlen = max(maxlen, right-left+1);
            right++;
            if (arr[right]==0)zeros+=1;
        }
        else {
            if (arr[left]==0)zeros--;
            left++;
        }
    }
    return maxlen;
}

int main(){
    bool arr[]={1,1,1,0,0,0,1,1,1,1,0};
    int size=sizeof (arr)/sizeof (arr[0]);
    int k=2;
    int result=maxconsecutiveones (arr, size, k);
    cout<<result<<"\n";
}