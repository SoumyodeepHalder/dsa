#include <iostream>
#include <stack>
using namespace std;

bool balancedparanthesis (string s){
    stack <char > st;
    for (int i=0;i <s.length ();i++){
        if (s[i]=='('|| s[i]=='{'||s[i]=='['){
            st.push (s[i]);
        }
        else if (s[i]==')'){
            if (st.top()=='('){
                st.pop ();
            }
            else return false;
        }
        else if (s[i]=='}'){
            if (st.top()=='{'){
                st.pop ();
            }
            else return false;
        }
        else if (s[i]==']'){
            if (st.top()=='['){
                st.pop ();
            }
            else return false;
        }
    }
    if (!st.empty ()) return false;
    return true;
}

int main (){
    string s= "[{()}]";
    cout<<balancedparanthesis (s)<<"\n";
}