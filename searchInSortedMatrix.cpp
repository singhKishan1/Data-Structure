#include <iostream>
#include <vector>
using namespace std;


bool solve(vector<vector<int>> matrix, int target){
	int n = matrix.size();
	int m = matrix[0].size();
	int i=0,j=m-1;
	while(i<n && j>=0){
		if(matrix[i][j]==target)
			return true;

		if(matrix[i][j]>target)
			--j;
		else
			++i;
	}

	return false;
}


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matrix;
	for(int i=0; i<n; ++i){
		vector<int> v(m);
		for(int j=0; j<m; ++j)
			cin>>v[j];
		matrix.push_back(v);
	}

	int target;
	cin>>target;

	cout << solve(matrix, target) << endl;
	return 0;
}