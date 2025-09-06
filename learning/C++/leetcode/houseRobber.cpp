#include <iostream>
#include <vector>

using namespace std;


    int solve(vector<int>&arr,int n, vector<int>&dp){
        if(n<=0)return 0;
        if(dp[n]!=-1)return dp[n];

        return dp[n] = max(solve(arr,n-1,dp), solve(arr,n-2,dp)+arr[n-1]);
    }

/*
int solve(int arr[],int n, int dp[]){
	if(n<=0)return 0;
	if(dp[n]!=-1)return dp[n];

	return dp[n] = max(solve(arr,n-1,dp), solve(arr,n-2,dp)+arr[n-1]);
}
*/

int main(){
	int n;cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; ++i)cin>>arr[i];
	vector<int>dp(n+1, -1);

	cout << solve(arr,n,dp) <<endl;
	return 0;
}
