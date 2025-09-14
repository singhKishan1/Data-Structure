#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>&v, int target){
	int n = v.size(), i=0,j=0;
	int ans = n, sum =0;
	while(j<n){
		sum += v[j];
		if(sum>=target){
			while(i<=j && sum>=target){
				ans = min(ans, j-i+1);
				sum -= v[i];
				++i;
			}
		}
		++j;
	}
	return ans == n ? 0 : ans;
}

int main(){
	cout << "Enter size: ";int n;cin>>n;
	vector<int> v(n);
	cout << "Enter element in array: ";
	for(int i=0; i<n; ++i)cin>>v[i];
	cout << "Enter target value: ";
	int target; cin>>target;
	cout << "Answer: " << solve(v, target) << endl;
	return 0;
}
