#include <bits/stdc++.h>

using namespace std;

int dfs(unordered_map<int, vector<int>>&mp , vector<bool>&vis,int id){
    

    int  ans = 0;
    if(vis[id]==false){
        vis[id] = true;
        for(int i=0; i<mp[id].size() && !vis[mp[id][i]]; ++i){
            ans += 1 + dfs(mp, vis, mp[id][i]);
        }

        vis[id] = false;
    }
    return ans;
}

vector<int> solve(vector<vector<int>> &v, int n){

    unordered_map<int, vector<int>> mp;
    for(int i=0; i<v.size(); ++i){
        mp[v[i][0]].push_back(v[i][1]);
        mp[v[i][1]].push_back(v[i][0]);
    }
    
    vector<pair<int,  int>> ansArray;
    vector<bool>vis(n,false);
    for(auto x:mp){
        ansArray.push_back({x.first,dfs(mp, vis, x.first)});
    }
    for(auto x:mp){
        cout <<x.first<<" --> ";
        for(int  i=0; i<x.second.size(); ++i)
            cout << x.second[i] << "  ";
        cout << endl;
    }


    cout << "answer \n";
    for(auto x:ansArray)
        cout <<x.first <<" --> " << x.second  <<endl;
    cout << endl;

    return {};
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n-1, vector<int>(2));
    for(int i=0; i<n-1; ++i)
        cin>>edges[i][0] >> edges[i][1];
    vector<int> ans = solve(edges, n);
    return 0;
}