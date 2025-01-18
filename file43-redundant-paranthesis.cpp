#include <bits/stdc++.h>
using namespace std;

bool redundant_paranthesis (string arr, int len){
    stack <bool > s;
    for (int i=0;i < len;i++){
        if (arr[i]=='('){
            s.push (1);
        }
        else if (arr[i]==')'){
            if (s.top ()) return 1;
            else s.pop ();
        }
        else {
            if (!s.empty ()){
                if (s.top ()){
                    s.pop ();
                    s.push (0);
                }
            }
        }
    }
    return 0;
}

int main(){
    string str= "((a+b)+(c+d))";
    bool ans = redundant_paranthesis (str, str.length ());
    cout<<ans<<"\n";
}