#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>&v, int k, int threshold){
	int n = v.size(), i=0,j=0,count = 0;
	long long sum = 0;
	while(j<n){
		sum += v[j];
		if((j-i+1)==k){
			int avg = sum/k;
			if(avg>=threshold) ++count;

			sum -= v[i];
			++i;
		}

		++j;
	}

	return count;
}

int main(){
	cout << "Enter size: ";int n;cin>>n;
	vector<int> v(n);
	cout << "Enter element in array: ";
	for(int i=0; i<n; ++i)cin>>v[i];
	cout << "Enter window size: ";int k;cin>>k;
	cout << "Enter threshold: ";int threshold; cin>>threshold;

	cout << "Answer: " << solve(v, k, threshold) << endl;
	return 0;
}
