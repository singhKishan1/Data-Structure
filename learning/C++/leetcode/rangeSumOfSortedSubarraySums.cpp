#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mod=1e9+7;
int solve(vector<int> v, int l, int r){
	int n = v.size();
	vector<int> arr;
	for(int i=0; i<n; ++i){
		int sum = v[i];
		arr.push_back(sum);
		for(int j=i+1; j<n; ++j){
			sum += v[j];
			arr.push_back(sum);
		}
	}

	//print all sub array sum
	for(auto x:arr)cout << x<< "\t";
	cout << endl;

	//sort array.
	sort(arr.begin(), arr.end());
	int rgSum=0;
	for(int i=l-1; i<r; ++i)
		rgSum =(rgSum+ arr[i])%mod;

	return rgSum;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)cin>>[i];

	int l,r;cin>>l>>r;
	cout << solve(v,l,r) << endl;
	return 0;
}
