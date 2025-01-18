#include <iostream>
using namespace std;

string longestsubstring (string s){
    string result="";
    result+=s[0];
    int maxlen=1;
    int left=0;
    int right=1;
    for (;right < s.length ();right++){
        bool isvalid=1;
        for (int j=left;j < right;j++){
            if (s[j]==s[right]){
                left=j+1;
                isvalid=0;
                break;
            }
        }
        if (isvalid){
            if (maxlen < right-left+1){
                result="";
                for (int i=left;i <= right;i++){
                    result+=s[i];
                    maxlen=right-left+1;
                }
            }
        }
    }
    return result;
}

int main(){
    string s="abcabcbb";
    // string s= "pwwkew";
    string result=longestsubstring (s);
    cout<<result<<"\n";
}