#include <iostream>
using namespace std;

int solve(string s){
	int ans = 1,cnt=1;
	for(int j=1; j<s.size(); ++j){
		if(s[j-1]+1==s[j]){
			++cnt;
			ans = max(ans,cnt);
		}else
			cnt =0;
	}
	return ans;
}

int main(){
	string s;cin>>s;
	cout<<solve(s)<<endl;
	return 0;
}
