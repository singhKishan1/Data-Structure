#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

string removeString(string s, int val, string str, int& ans){
    stack<char> st;
    for(int i=0; i<s.size(); ++i){
        if(st.size()==0)
            st.push(s[i]);
        else{
            string temp = "";
            temp += st.top();
            temp += s[i];
            cout << temp << endl;
            if (temp == str)
            {
                st.pop();
                ans += val;
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    // cout  << ans << endl;
    s = "";
    while(st.size()>0){
        s += st.top();
        st.pop();
    }
    // cout << s << endl;
    reverse(s.begin(), s.end());
    return s;
}

int solve(string s, int x, int y){
    
    int ans = 0;
    if(x>y){
        s = removeString(s, x, "ab", ans);
        s = removeString(s, y, "ba", ans);
    }else{
        s = removeString(s, y, "ba", ans);
        s = removeString(s, x, "ab", ans);
    }

    return ans;
    
}

int main(){
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;

    cout << solve(s, x, y) << endl;
    return 0;
}