#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>&v, int k){
	int n = v.size();
	vector<int>pf(n,0);
	pf[0]=v[0];
	for(int i =1;  i<n;++i)
		pf[i] =  pf[i-1]+v[i];

	k =  k%pf[n-1];
	int ans =  v[0];
	for(int i =0; i<n; ++i){
		if(pf[i]>k){
			ans = i;
			break;
		}
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int>v(n);
	for(int  i=0;i<n;++i)
		cin>>v[i];

	int k;
	cin>>k;
	cout << solve(v, k) << endl;
	return 0;
}
