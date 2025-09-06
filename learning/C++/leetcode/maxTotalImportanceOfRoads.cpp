#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &rd, int n){

    unordered_map<int,vector<int>>mp;
    for(auto  x:rd){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }

    priority_queue<pair<int, int>> pq;
    for(auto x:mp){
        pq.push({x.second.size(), x.first});
    }

    unordered_map<int, int> nd;
    while(pq.size()>0){
        nd[pq.top().second] = n;
        --n;
        pq.pop();
    }

    int sum = 0;
    for(auto x:mp){
        
            sum += nd[x.first];
            for(auto y:x.second){
                if(nd.find(y)!=nd.end()){
                    sum += nd[y];
                }
            }

            nd.erase(x.first);
        
    }

    return sum;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> rd;
    for(int i=0; i<m; ++i){
        int x,y;cin>>x>>y;
        rd.push_back({x,y});
    }

    cout << solve(rd, n) << endl;
    return  0;
}