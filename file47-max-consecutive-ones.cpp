#include <iostream>
using namespace std;

int maxconsecutiveones (bool* arr, int size){
    int output=0;
    for (int i=0;i < size; i++){
        if (arr[i]){
            int current=1;
            while (i < size-1 &&  arr[i+1]){
                i++;
                current++;
            }
            output=max (output, current);
        }
    }
    return output;
}

int main(){
    bool arr[]={1,1,1,0,0,0,1,1,1,1};
    int size=sizeof (arr)/sizeof (arr[0]);
    int result = maxconsecutiveones (arr, size);
    cout<<result<<"\n";
}