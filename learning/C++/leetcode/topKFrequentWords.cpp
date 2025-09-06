#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using pq = priority_queue<string, vector<string>, greater<string>>;

void solve(vector<string> v, int k){
    unordered_map<string, int> mp;
    for(auto x:v)
        mp[x]++;

    
    map<int, pq>mp2;
    for(auto x:mp){
        string key = x.first;
        int val = x.second;
        mp2[val].push(key);
    }

    for(auto it=mp2.rbegin(); it!=mp2.rend() && k>0; it++){
        pq pq1 = it->second;
        while(pq1.size()>0 && k>0){
            cout << pq1.top() << endl;
            pq1.pop();
            --k;
        }
    }

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    solve(v, k);
    return 0;
}