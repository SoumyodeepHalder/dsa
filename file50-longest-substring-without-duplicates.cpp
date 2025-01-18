#include <iostream>
using namespace std;

string longestsubstring (string s){
    string result = "";
    result += s[0];
    int maxlen=1;
    bool isvalid=1;
    int duplicatelocation=0;
    int left=0;
    int right=1;

    while (right < s.length ()){
        isvalid=1;
        for (int i=left;i <right ; i++){
            if (s[i]==s[right]){
                isvalid=0;
                duplicatelocation=i;
            }
        }
        if (isvalid){
            if (maxlen < right - left +1){
                maxlen=right-left+1;
                result="";
                for (int j=left; j <= right ; j++){
                    result+=s[j];
                }
            }
            right++;
        }
        else left=duplicatelocation+1;
    }
    return result;
}

int main(){
    string s = "abcabcbb";
    string result ="";
    result = longestsubstring (s);
    cout<< result<<"\n";
}