#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

char maxOdd(map<char, int> &mp){
    char ch='0';int cnt=INT32_MIN;
    for(auto x:mp){
        if(x.second&1 && ch<x.first){
            ch = x.first;
            cnt = x.second;
        }
    }

    return ch;
}

string solve(string s){
    map<char, int> mp;
    for(int i=0; i<s.size(); ++i)
        mp[s[i]]++;
    
    if(mp['0']==s.size())
        return "0";
    
    char ch = maxOdd(mp);

    string temp = "";
    for(auto it=mp.rbegin(); it!=mp.rend(); ++it){
        temp = temp + string((it->second)/2, it->first);
    }

    if(temp.size()>0 && temp[0]=='0')
        return string(1, ch);
    
    string temp2 = temp;
    reverse(temp.begin(), temp.end());
    return temp2 + ch + temp;
}

int main(){
    string s;
    cin>>s;
    cout << solve(s) << endl;
    return 0;
}