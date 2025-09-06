#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int>&v, vector<int>&dp, int i, int k){
    int n = v.size();
    if(i>=n)
        return 0;
    
    if(dp[i]!=INT32_MIN)
        return dp[i];
    
    return dp[i] = v[i] +dfs(v, dp, v[i]+k, k);   
}

int solve(vector<int> v, int k){
    int n = v.size();
    vector<int> dp(n,INT32_MIN);
    int ans = INT32_MIN;
    for(int i=0; i<n; ++i)
        ans = max(ans, dfs(v, dp, i, k));
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    int k;
    cin>>k;

    cout<< solve(v, k) << endl;
    return 0;
}