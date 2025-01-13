#include <iostream>
#include <stack>
using namespace std;

int precedance (char c){
    if (c=='^')
    {
        return 3;
    }
    else if ((c=='*')||(c=='/')){
        return 2;
    }
    else if((c=='+')||(c=='-')){
        return 1;
    }
    else return 0;
}

string infixtopostfix(string s)
{
    stack <char > st;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='('){
            st.push (s[i]);
        }
        else if (s[i]==')'){
            while (st.top ()!='(')
            {
                ans+=st.top ();
                st.pop ();
            }
            st.pop ();
        }
        else if(s[i] >= '0' && s[i] <='9'){
            ans+=s[i];
        }
        else {
            while ((!st.empty ())&&(precedance (st.top ()>precedance(s[i]))))
            {
                ans+=st.top ();
                st.pop ();
            }
            st.push (s[i]);
        }
    }
    while (!st.empty ()){
        ans+=st.top ();
        st.pop ();
    }
    return ans;
}

int main(){
    string infix= "(2-3/4)*(5/6+4)";
    cout<<infixtopostfix (infix)<<"\n";
}