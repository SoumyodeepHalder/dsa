#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

void display(stack <string > st){
    while (st.empty ()!= 1) {
        cout<<st.top()<<"\n";
        st.pop ();
    }
}

string reverse(string s){
    stack <string > st;
    string temp="";
    for(int i=0;i<s.length ();i++){
        if(s[i]==' '){
            st.push (temp);
            temp="";
        }
        else{
            temp+=s[i];
        }
    };
    st.push (temp);
    temp= "";
    display (st);
    while (st.empty ()!= 1){
        temp.append (st.top ());
        temp+=' ';
        st.pop ();
    }
    temp.pop_back ();
    return temp;
}

int main(){
    string s="hey, how are you doing";
    s=reverse (s);
    cout<<s<<"\n";
}