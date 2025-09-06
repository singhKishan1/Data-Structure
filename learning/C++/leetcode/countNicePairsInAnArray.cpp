#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solve(vector<int> &v){
	vector<int> rev(v.size());
	for(int i=0; i<v.size(); ++i){
		int num = v[i];
		int revNum = 0;
		while(num>0){
			revNum = (revNum * 10) + (revNum % 10);
			num = num /10;
		}

		rev.push_back(revNum);
	}

	unordered_map<int, vector<int>> mp;
	for(int i=0; i<v.size(); ++i){
		mp[v[i]-rev[i]].push_back(i);
	}

	int count = 0;
	for(int i=0; i<v.size(); ++i){
	
		int x = v[i] - rev[i];
		if(mp.find(x)!=mp.end()){
			auto l = lower_bound(mp[x].begin(), mp[x].end(), i);
			if(l != mp[x].end())
				count += *l;
		}
		
	}

	return count;
}

int main(){
	int n; cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i)cin>>v[i];
	cout << solve(v) << endl;
	return 0;
}
