#include <iostream>
#include <vector>

using namespace std;

/**
 *
void solve(vector<int> &v, int k){
	int i=k, n = v.size();
	int sum = 0;
	for(int j=0; j<i+k && j<n; ++j){
		sum += v[j];
	}
	vector<int> ans(n, -1);
	while((i-k)>=0 && (i+k)<n){
		sum += v[i+k];
		ans[i] = sum/(2*k+1);
		sum -= v[i-k];
		++i;
	}

	for(int j=0; j<n; ++j){
		cout << ans[j] << " ";
	}cout << endl;
}

**/

void solve(vector<int> &v, int k){
	int n = v.size();
	vector<int> ans(n, -1);
	if(k==0)return v;
	if(2*k+1>n)return ans;

	long long sum = 0;
	int windowSize = 2*k+1;
	for(int j=0; j<windowSize; ++j)
		sum += v[j];

	ans[k] = sum/windowSize;
	for(j=k+1; j+k<n; ++j){
		sum += v[j+k];
		sum -= v[j-k-1];
		ans[j] = sum/windowSize;
	}

	for(int i=0; i<n; ++i){
		cout << ans[i] << " ";
	}cout << endl;

}


int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i)cin>>v[i];
	int k;cin>>k;
	solve(v, k);
	return 0;
}
