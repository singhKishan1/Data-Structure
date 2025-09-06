#include <iostream>
//#include <unordered_set>
//#include <string>

using namespace std;

/*
unordered_set<string>st;

void solve(int n, string s){
	if(n<0)return;
	if(n==0){
		st.insert(s);
		return;
	}

	s.push_back('1');
	solve(n-1,s);
	s.pop_back();
	s.push_back('2');
	solve(n-2,s);
	return;
}
*/

int dp[46];

int solve(int n){
	if(n==0)return 1;
	if(n<0)return 0;
	if(dp[n]!=-1)return dp[n];
	return dp[n] = solve(n-1)+solve(n-2);
}

int main(){
	int n;
	cin>>n;
//	solve(n, "");
//	cout <<st.size() <<endl;
	for(int i=0;i<46;++i)dp[i]=-1;
	cout << solve(n) << endl;

	return 0;
}
