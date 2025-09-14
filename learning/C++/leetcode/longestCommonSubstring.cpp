#include <iostream>
#include <vector>

using namespace std;

int solve(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){

	if(i>=s1.size() || j>=s2.size())return 0;
	if(dp[i][j] != -1)return dp[i][j];

	if(s1[i]==s2[j]){
		return dp[i][j] = 1 + solve(s1, s2, i+1, j+1, dp); 
	}else dp[i][j] = 0;

	return dp[i][j];

}


int longestCommonSubstring(string &s1, string &s2){
	int ans = 0, n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			ans = max(ans, solve(s1, s2, i, j,dp));
		}
	}
	return ans;
}

int main(){
	cout << "Enter first string: ";
	string s1; cin>>s1;
	cout << "Enter second string: ";
	string s2; cin>>s2;

	cout << "Answwer: " << longestCommonSubstring(s1, s2) <<endl;
	return 0;
}
