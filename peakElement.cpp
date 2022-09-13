#include <iostream>
using namespace std;

int solve(int arr[], int n){
	if(n==1)return 0;
	int low = 0, high = n-1;
	while(low<=high){
		int mid = low+(high-low)/2;
		if(mid-1>=0 && mid+1<n){
			if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
				return mid;
			}

			// for moving towards left either right.
			if(arr[mid+1]>arr[mid])
				low = mid+1;
			else
				high = mid-1;
		}else if(mid==0 && mid+1<n){
			if(arr[mid]>arr[mid+1])
				return mid;

			low = mid+1;
		}else if(mid==n-1 && mid-1>=0){
			if(arr[mid]>arr[mid-1])
				return mid;

			high = mid-1;
		}
	}

	return -1;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; ++i)cin>>arr[i];

	cout << solve(arr, n) << endl;
	return 0;
}