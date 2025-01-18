#include <iostream>
#include <stack>
using namespace std;

int maxconsecutiveones (bool* arr, int size){
    stack <bool > s;
    int ans=0;
    for (int i=0; i < size; i++){
        int current=0;
        if (arr[i]==0){
            while (!s.empty () && s.top ()){
                s.pop ();
                current++;
            }
            ans=max (ans, current);
        }
        else s.push (arr[i]);
    }
    int current=0;
    while (!s.empty () && s.top ()){
        s.pop ();
        current++;
    }
    ans=max (ans, current);
    return ans;
}

int main(){
    bool arr[]={1,1,1,0,0,0,1,1,1,1};
    int size=sizeof (arr)/sizeof (arr[0]);
    int result = maxconsecutiveones (arr, size);
    cout<<result<<"\n";
}