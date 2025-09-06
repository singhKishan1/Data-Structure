#include<iostream>
using namespace std;

long long solve(int arr[], int n){
	long long ans=0,cnt=0;
	for(int i=0; i<n; ++i){
		if(arr[i]==0)++cnt;
		else{
			ans += cnt*(cnt+1)/2;
			cnt=0;
		}
	}

	if(cnt>0)
		ans += cnt*(cnt+1)/2;

	return ans;
}

int main(){
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)cin>>arr[i];
	cout << solve(arr,n) << endl;
	return 0;
}
