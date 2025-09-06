#include <iostream>
#include <vector>

using namespace std;

int trappingRainWater(vector<int>heights){
	int n = heights.size();
	vector<int> mxl(n),mxr(n);
	mxl[0] = heights[0];
	for(int i=1; i<n; ++i){
		mxl[i] = max(mxl[i-1], heights[i]);
	}

	mxr[n-1] = heights[n-1];
	for(int i=n-2; i>=0; --i)
		mxr[i] = max(mxr[i+1], heights[i]);

	vector<int>water(n,0);
	for(int i=0; i<n; ++i){
		water[i] = min(mxl[i], mxr[i]) - heights[i];
	}

	int sum = 0;
	for(int i=0; i<n; ++i)sum += water[i];

	return sum;
}

int main(){
	vector<int> v={4,2,0,3,2,5};
	cout << trappingRainWater(v) << endl;
}