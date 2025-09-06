#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(vector<int> v1, vector<int> v2, int k){
    int n = v1.size(), m = v2.size();
    unordered_map<int, int> mp;

    
    for(int i=0; i<m; ++i)
        mp[v2[i]]++;


    ll ans = 0;    
    for(int i=0; i<n; ++i){
        if(mp.find(v1[i]/k)!=mp.end())
            ans += mp[v1[i]/k];
    }

    return ans;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v1(n), v2(m);
    for(int i=0; i<n; ++i)
        cin>>v1[i];
    
    for(int i=0; i<m; ++i)
        cin>>v2[i];
    
    int k;cin>>k;
    cout << solve(v1, v2, k) << endl;

    return 0;    
}