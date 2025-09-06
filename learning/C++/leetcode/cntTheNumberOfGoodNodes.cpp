#include  <iostream>
#include  <vector>
#include  <unordered_map>
#include  <algorithm>


using namespace std;

int ans=0;

int dfs(unordered_map<int,vector<int>> &mp, int  id,vector<int>& vs){
	if(mp.find(id)==mp.end())return 0;

	if(vs[id]==1)return 0;
	vs[id] = 1;

	vector<int> temp;
	for(auto x:mp[id]){
		temp.push_back(dfs(mp,x, vs));
	}

	sort(temp.begin(), temp.end());
	if(temp.size()==1)++ans;
	else{
		bool check = true;
		for(int i=0; i<temp.size()-1; ++i){
			if(temp[i]!=temp[i+1])check=false;
		}

		if(check)++ans;
	}
	


	return *max_element(temp.begin(), temp.end())+1;
}


int solve(vector<vector<int>>eg){
	unordered_map<int,vector<int>>mp;
	for(int i=0; i<eg.size();  ++i)
		mp[eg[i][0]].push_back(eg[i][1]);


	vector<int> vs(eg.size(), 0);
	dfs(mp, 0, vs);
	return ans;
}

	

int main(){
	int n;
	cin>>n;
	vector<vector<int>> eg;
	for(int i=0; i<n; ++i){
		int x,y;cin>>x>>y;
		eg.push_back({x,y});
	}

	cout << solve(eg) << endl;
	return 0;

}
