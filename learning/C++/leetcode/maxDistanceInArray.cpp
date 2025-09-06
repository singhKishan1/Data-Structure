#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &arr){
	int n = arr.size();
	priority_queue<pair<int, int>> pq;
	for(int i=0; i<n; ++i)	
		pq.push({arr[i].back(), i});

	int ans = 0;
	for(int i=0; i<n; ++i){
		if(pq.top().second == i){
			pair<int, int> pd  = pq.top();
			pq.pop();
			ans = max(ans, abs(arr[i][0] - pq.top().first));
			pq.push(pd);
		}else{
			ans = max(ans, abs(arr[i][0] - pq.top().first));
		}
	}

	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> arr;
	for(int i=0; i<n; ++i){
		int m;cin>>m;
		vector<int> temp(m);
		for(int j=0; j<m;  ++j)
			cin>>temp[j];

		arr.push_back(temp);
	}

	cout << solve(arr) << endl;
	return 0;
}
