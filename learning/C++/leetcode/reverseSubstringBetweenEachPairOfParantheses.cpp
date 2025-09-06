#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string solve(string s){
    stack<string> st;
    string temp = "";
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='('){
            
            st.push(temp);
            temp = "";
        }else if(s[i]>='a' && s[i]<='z'){
            temp += s[i];
        }else{
            reverse(temp.begin(),temp.end());
            if(st.size()>0){
                temp = st.top()+temp;
                st.pop();
            }
        }
    }

    return temp;
}

int main(){
    string s;
    cin>>s;
    cout << solve(s) << endl;
    return 0;
}