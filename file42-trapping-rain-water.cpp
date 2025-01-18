#include <bits/stdc++.h>
using namespace std;

int trapping_rain_water (vector <int > v){
    int maxleft = v[0];
    int maxright = v[v.size ()-1];
    int left=1;
    int right=v.size ()-2;
    int ans=0;

    while (left <= right){
        int mini=min (maxleft, maxright);
        if (mini==maxleft){
            // if (maxleft > v[left]) {
            //     ans+= mini-v[left];
            // }
            // else maxleft=v[left];
            maxleft=max (maxleft, v[left]);
            ans+=maxleft-v[left];
            left++;
        }
        else {
            // if (maxright > v[right]){
            //     ans+= maxright-v[right];
            // }
            // else maxright=v[right];
            maxright=max (maxright, v[right]);
            ans+=maxright-v[right];
            right--;
        }
    }
    return ans;
}

int main (){
    vector <int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int max=trapping_rain_water (arr);
    cout<<max<<"\n";
}