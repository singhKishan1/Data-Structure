#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int checkSubstr(string s,unordered_map<string, int> mp, int id, int k){
    int i=id;
    for(; i<s.size()-k+1 && mp.size()>0; i+=k){
        string str = s.substr(i, k);
        if(mp.find(str)!=mp.end()){
            mp[str]--;
            if(mp[str]==0)
                mp.erase(str);
        }else{
            return -1;
        }
    }

    if(mp.size()==0){
        return id;
    }
    return -1;
}

void solve(vector<string> &v, string s){
    int k = v[0].size();
    vector<int> ans;
    unordered_map<string, int> mp;
    for(auto x:v)
        mp[x]++;
    
    int i=0,j=0,n=s.size();
    while(j<n-k+1){
        string str = s.substr(j, k);
        if(mp.find(str)!=mp.end()){
            int val = checkSubstr(s, mp, j, k);
            if(val!=-1){
                ans.push_back(val);
            }
        }
        ++j;
    }

    for(auto x:ans)
        cout << x << " ";
    cout << endl;
}

int main(){
    string s;
    cin>>s;

    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; ++i)cin>>v[i];

    solve(v, s);
    return 0;
}

/**
 * 
 *     int checkSubstr(string s,unordered_map<string, int> mp, int id, int k){
        int i=id;
        for(; i<s.size() && mp.size()>0; i+=k){
            string str = s.substr(i, k);
            if(mp.find(str)!=mp.end()){
                mp[str]--;
                if(mp[str]==0)
                    mp.erase(str);
            }else{
                return -1;
            }
        }

        if(mp.size()==0){
            return id;
        }
        return -1;
    }

    vector<int> findSubstring(string s, vector<string>& v) {
        int k = v[0].size();
        vector<int> ans;
        unordered_map<string, int> mp;
        for(auto x:v)
            mp[x]++;
        
        int len = v.size()*k;

        int i=0,j=0,n=s.size();
        while(j<n-len+1){
            string str = s.substr(j, k);
            if(mp.find(str)!=mp.end()){
                if(checkSubstr(s, mp, j, k)!=-1){
                    ans.push_back(j);
                }
            }
            ++j;
        }
        return ans;
    }
*/