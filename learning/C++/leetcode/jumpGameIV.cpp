#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


int visited[50002], dp[50002];

int solve(vector<int> arr, int id, unordered_map<int,vector<int>>mp){
    int n = arr.size();
    queue<int> q1;
    visited[id] = 1;
    dp[id] = 0;
    q1.push(id);

    while(q1.size()>0){
        id = q1.front(); 
        q1.pop();
        if(id==n-1)return dp[n-1];

        if(id-1>=0 && visited[id-1]!=1){
            visited[id-1] = 1;
            dp[id-1] = dp[id] + 1;
            q1.push(id-1);
        }

        if(id+1<n && visited[id+1]!=1){
            visited[id+1] = 1;
            dp[id+1] = dp[id] + 1;
            q1.push(id+1);
        }

        for(auto x:mp[arr[id]]){
            if(visited[x]!=1){
                visited[x] = 1;
                dp[x] = dp[id]+1;
                q1.push(x);
            }
        }

        mp[arr[id]].clear();
    }

    return dp[n-1];

}

int jumpGameIV(vector<int> v)
{
    int n = v.size();
    vector<int> dp(n, 0);
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i)
    {
        mp[v[i]].push_back(i);
    }

    return solve(v,0,mp);
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << jumpGameIV(arr) << endl;
    return 0;
}