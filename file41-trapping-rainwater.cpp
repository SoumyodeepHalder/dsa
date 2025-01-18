#include <iostream>
#include <vector>
using namespace std;

void vectorprinter (vector <int > v){
    for (auto i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int maxwater (vector <int > arr){
    vector <int > maxleft;
    vector <int > maxright;
    maxleft.push_back (arr[0]);
    maxright.push_back (arr[arr.size ()-1]);
    for (int i=1;i < arr.size ();i++){
        if (arr[i] > maxleft.back ())maxleft.push_back (arr[i]);
        else maxleft.push_back (maxleft.back ());
    }
    for (int i=arr.size ()-2;i >=0; i--){
        if (arr[i] > maxright.front ())maxright.insert (maxright.begin (), arr[i]);
        else maxright.insert (maxright.begin (), maxright.front ());
    }
    int ans=0;
    for (int i=0;i < arr.size ();i++){
        if (arr[i] < min (maxleft[i], maxright[i])){
            ans+=min (maxleft[i], maxright[i])-arr[i];
        }
    }
    return ans;
}

int main(){
    vector <int > arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int max=maxwater (arr);
    cout<<max<<"\n";
}