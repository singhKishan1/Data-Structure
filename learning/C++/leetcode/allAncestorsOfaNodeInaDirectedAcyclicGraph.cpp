#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

void solve(vector<vector<int>> &edges, int n){
    unordered_map<int, vector<int>> mp;
    for(auto x:edges){
        mp[x[0]].push_back(x[1]);
    }

    map<int, unordered_set<int>> ans;
    for(int i=0; i<n; ++i){
        vector<int> v = mp[i];
        for(auto x:v){
            ans[x].insert(i);
            for(auto y:ans[i])
                ans[x].insert(y);
        }
    }

    cout << "\nPrinting: \n";
    for(auto x:ans){
        cout << x.first << " ---> ";
        for(auto y:x.second)
            cout << y << " ";
        cout << endl;
    }
}

// void dfs(unordered_map<int, vector<int>> &mp, int pr, int child, map<int,set<int>> &ans){


//     if(mp[child].size()==0 || mp.find(child)==mp.end())
//         return;
    
//     for(auto x:mp[child]){
//         ans[x].insert(pr);
//         dfs(mp, pr, x,  ans);
//     }

//     return;

// }

// void solve(vector<vector<int>> &edges,  int n){
//     unordered_map<int, vector<int>> mp;
//     for(auto x:edges){
//         mp[x[0]].push_back(x[1]);
//     }

//     cout << "\nPrinting: \n";
//     // for(auto x:mp){
//     //     cout << x.first <<  " ---> ";
//     //     for(auto y:x.second)
//     //         cout << y << " ";
//     //     cout << endl;
//     // }

//     map<int, unordered_set<int>>ans;

//     for(int i=0; i<n; ++i){
//         vector<int> v = mp[i];
//         for(auto x:v){
            
//         }
//     }

//     // for(auto x:mp){
//     //     dfs(mp, x.first, x.first, ans);
//     // }

//     for(auto x:ans){
//         cout << x.first << " ---> ";
//         for(auto y:x.second)
//             cout <<  y <<  " ";
//         cout << endl;
//     }


// }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges;
    int m;cin>>m;
    for(int i=0; i<m; ++i){
        int x,y;cin>>x>>y;
        edges.push_back({x,y});
    }

    solve(edges, n);
    return 0;
}