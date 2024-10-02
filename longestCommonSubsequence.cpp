#include <iostream>
#include <vector>
using namespace std;

/**
 * @param string s1
 * @param string s2
 * @param string i
 * @param string j
 * @param string vector<vector<int>>
 * @return integer
 * */
int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
	if (i < 0 || j < 0)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s1[i] != s2[j])
		return dp[i][j] = max(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i, j - 1, dp));
	else
		return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp)+1;
}

/*
 * return the length  of longest common subsequene between
 * two strings.
 * */
int longestCommonSubsequence(string s1, string s2)
{
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	return solve(s1, s2, n - 1, m - 1, dp);
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << longestCommonSubsequence(s1, s2) << endl;
	return 0;
}
