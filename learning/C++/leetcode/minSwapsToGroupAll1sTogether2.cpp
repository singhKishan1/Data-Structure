#include <iostream>
#include <vector>

using namespace  std;

/*
 * function for solve the problem, which return min number of swaps 
 * group all 1s in array*/
int solve(vector<int> v){
	vector<int> arr;
	int n =  v.size();

	// counting  zeros
	for(int  i=0; i<n; ++i){
		if(v[i]==0){
			arr.push_back(0);
			while(i<n && v[i]==0){
				arr[arr.size()-1]++;
				++i;
			}
		}
	}

	// printing
	for(auto x:arr)
		cout  << x  <<  "\t";
	cout  << endl;

	cout << "\n";
	int cnt = 0;
	for(int i=0; i<n-1; ++i){
		
		if(i==0){
			cnt =  min(arr[n-1]+arr[i],arr[i+1]);
		}else{
			cnt += min(min(arr[i],arr[i+1]),cnt);
		}
		
	}

	return cnt;
	
}


/*
 * Main function....
 * */
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n;  ++i)cin>>v[i];
	cout  << solve(v) << endl;
	return 0;
}
