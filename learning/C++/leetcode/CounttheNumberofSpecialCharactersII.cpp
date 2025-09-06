#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solve(string s){
    int count = 0;
    vector<int> last(26, -1), first(26, -1);
    for(int i=0; i<s.size(); ++i){
        if(islower(s[i])){
            last[s[i]-'a'] = i;
        }else if(isupper(s[i]))
            first[s[i]-'A'] = i;
    }

    for(int i=0; i<26; ++i){
        if(last[i]!=-1 && last[i]<first[i])
            ++count;
    }

    return count;
}

int main(){
    string s;
    cin>>s;

    cout << solve(s) << endl;
    return 0;
}