#include <iostream>
#include <stack>
using namespace std;

int largest_rectangle (int* arr, int size){
    int max=0;
    stack <int > index;
    stack <int > value;
    index.push (0);
    value.push (arr[0]);
    for (int i=1;i < size; i++){
        if (arr[i] > value.top ()){
            index.push (i);
            value.push (arr[i]);
        }
        else {
            int noofpop=0;
            while (!index.empty () && arr[i] < value.top ()){
                int poppedarea=value.top ()*noofpop+1;
                if (poppedarea > max)max=poppedarea;
                index.pop ();
                value.pop ();
                noofpop++;
            }
            index.push (i-noofpop);
            value.push (arr[i]);
        }
    }
    if (!index.empty ()){
        int area=(size-index.top ())*value.top ();
        if (area > max)max = area;
        index.pop ();
        value.pop ();
    }
    return max;
}

int main(){
    int arr[]={2,1,5,6,2,3};
    int size=sizeof (arr)/sizeof (arr[0]);
    int largest=largest_rectangle (arr, size);
    cout<<largest<<"\n";
}