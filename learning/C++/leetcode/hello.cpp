#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> v){
    for(auto x:v)
        cout << x << " ";
    cout << endl;
}

void dfs(vector<vector<int>> &eg, vector<int>&dp,int sum, int id){
    if(id>=eg.size())
        return;
    
    if(dp[id]==-1)
        dp[id] = sum;

    for(int neig : eg[id])
        if(dp[neig]==-1)
            dfs(eg,dp,sum+1,neig);

}

vector<int> solve(vector<vector<int>> eg){
    int n = eg.size();
    vector<int> dp(n, -1);
    dfs(eg, dp, 0, 0);
    display(dp);
    return {};
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));
    for(int i=0;i<n-1; ++i)
        cin>>edges[i][0] >> edges[i][1];
    
    cout << "Sans: ";
    display(solve(edges));
}