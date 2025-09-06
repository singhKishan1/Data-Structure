#include  <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>>edges){
    unordered_map<string, vector<int>> mp;
    int cnt = 0;
    for(auto x:edges){
        string t1 = to_string(x[1])+"#"+to_string(x[2]);
        string t2 = to_string(x[2])+"#"+to_string(x[1]);

        if(x[0]!=3){
            vector<int> v = mp[t1];
            bool check = false;
            for(int i=0; i<v.size(); ++i){
                if(v[i] == x[0] || v[i]==3)
                    check = true;
            }

            if(!check)
                v.push_back(x[0]);
        }else{
            vector<int> v = mp[t1];
            while(v.size()>0)
                v.pop_back();
            
            v.push_back(x[0]);
            mp[t1] = v;
            mp[t2] = v;
        }
    }

    return 0;
}

int main(){

}