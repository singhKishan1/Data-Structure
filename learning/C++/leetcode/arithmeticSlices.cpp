#include <iostream>

using namespace std;

int solve(int arr[], int n)
{

	if(n<3)return 0;

	int ans =0;
	int cnt=0;
	for(int i=0,j=0;j<n;++j){
		if(j-i+1>=3){
			if((arr[i+1]-arr[i])==(arr[j]-arr[j-1])){
				++cnt;
			}else{
				ans += cnt*(cnt+1)/2;
				cnt = 0;
				while(i<j)++i;

			}
		}
	}
	
	if(cnt>0)ans += cnt*(cnt+1)/2;
	return ans;

}	

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << solve(arr, n) << endl;
	return 0;
}
