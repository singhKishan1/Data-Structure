#include <iostream>
#include <vector>

using namespace std;

int dp[105][105];

int solve(vector<vector<int>> arr, int m, int n, int i, int j){
  if(i<m &&  j<n && arr[i][j]==1)
     return 0;
 
  if(i==(m-1) && j==(n-1))
     return 1;
 
  if(dp[i][j]!=1)
      return 0;
  
  int val = 0;
  if(i<m)
    val = solve(arr, m, n, i+1, j);
 
  if(j<n)
    val += solve(arr, m, n, i, j+1);
 
  return dp[i][j] = val;
}

int main(){
  memset(dp, -1, sizeof(dp));
  int m,n;
  cin>>m>>n;
  vector<vector<int>> arr;
  for(int i=0; i<m; ++i){
    vector<int> v(n);
    for(int j=0; j<n; ++j)
        cin>>v[i];
    
    arr.push_back(v);
  }
  
  dp[0][0] = solve(arr, m, n, 0, 0);
  cout << dp[0][0] << endl;
  return 0;
}
