#include <iostream>
using namespace std;
int dp[105][105];

int solve(int m, int n, int i, int j){
  if(i==m && j==n)
    return 1;
 
  if(dp[i][j]!=-1)
      return dp[i][j];
  
  int val = 0;
  if(i<=m)
    val = solve(m, n, i+1, j);
  
  if(j<=n)
     val += solve(m, n, i, j+1);
 
  return dp[i][j] = val;
  return dp[i][j];
}

int main(){
  memset(dp, -1, sizeof(dp));
  int m, n;
  cin>>m>>n;
  dp[1][1] = solve(m, n, 1, 1);
  cout << dp[1][1] << endl;
  return 0;
}
