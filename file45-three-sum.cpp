#include <iostream>
using namespace std;

void bubblesort (int* arr, int size){
    for (int i=0;i < size-1;i++){
        int min=i;
        for (int j=i+1;j < size; j++){
            if (arr[min] > arr[j])min=j;
        }
        if (arr[min]!=arr[i]){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

void threesum (int* arr, int size,int target, int* ans){
    bubblesort (arr, size);
    for (int i=0; i < size-2;i++){
        int left=i+1;
        int right=size-1;
        while (left < right){
            int sum=arr[left]+arr[right]+arr[i];
            if (sum==target){
                ans[0]=arr[i];
                ans[1]=arr[left];
                ans[2]=arr[right];
                return;
            }
            else if (sum < target){
                left++;
            }
            else right--;
        }
    }
    cout<<"not found"<<"\n";
}

int main(){
    // int arr[]={-3,3,4,-3,1,2};
    int arr[]={1,3,6,7,9,12};
    int size=sizeof (arr)/sizeof (arr[0]);
    int target=24;
    int ans[3];
    threesum (arr, size, target,ans);
    for (int i=0;i <3; i++){
        cout<<ans[i]<<" ";
    }
}