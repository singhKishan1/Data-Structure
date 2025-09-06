#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>edges;
    for(int i=0; i<n-1; ++i){
        int x,y;cin>>x>>y;
        edges.push_back({x,y});
    }

    unordered_map<int, vector<int>> mp;
    for(auto x:edges){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }


    for(auto x:mp){
        vector<int> v = x.second;
        cout << x.first << " ---> ";
        for(auto y:x.second)
            cout << y << " ";
        cout  << endl;
    }

    return 0;
}