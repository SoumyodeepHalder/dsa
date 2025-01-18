#include <iostream>
using namespace std;

void twosum (int* arr, int size, int* ans, int target){
    int left=0;
    int right=size-1;
    while (left < right){
        int sum=arr[left]+arr[right];
        if (sum==target){
            ans[0]=arr[left];
            ans[1]=arr[right];
            return;
        }
        else if (sum < target){
            left++;
        }
        else right--;
    }
}

int main(){
    int arr[]= {1,3,4,5,7,10,11};
    int target=9;
    int size=sizeof (arr)/sizeof (arr[0]);
    int answer[2];
    twosum (arr, size, answer, target);
    cout<<answer[0] <<',' <<answer[1]<<"\n";
}