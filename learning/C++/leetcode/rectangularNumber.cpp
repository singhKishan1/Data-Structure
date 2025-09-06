#include <iostream>
using namespace std;

int main(){
	int m;
	cin>>m;
	int  cnt =m;
	int n = m*2-1;
	int arr[n][n];
	
	for(int start=0; start<m; ++start){
		for(int i=start; i<n-start; ++i)
			arr[start][i] = cnt;
		for(int i=start+1; i<n-start; ++i)
			arr[i][n-start-1] = cnt;
		for(int i=n-start-1; i>=start; --i)
			arr[n-start-1][i]=cnt;
		for(int i=n-start-2; i>start; --i)
			arr[i][start]=cnt;

		--cnt;
	}

	//printing....
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
			cout << arr[i][j] << "\t";
		cout<<endl;
	}
	return 0;
}
