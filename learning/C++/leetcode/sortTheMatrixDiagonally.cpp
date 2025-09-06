#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<vector<int>> &mat){
	int m = mat.size(), n = mat[0].size();
	vector<vector<int>> v;

	for(int i=0; i<n; ++i){
		vector<int> temp;
		for(int j=i, k=0; j<n && k<m; ++j, ++k)
			temp.push_back(mat[k][j]);
		sort(temp.begin(), temp.end());
		int cnt = 0;
		for(int j=i, k=0; j<n && k<m; ++j, ++k)
			mat[k][j] = temp[cnt++];
	}

	for(int i=1; i<m; ++i){
		vector<int> temp;
		for(int j=i, k=0; j<m && k<n; ++j, ++k)
			temp.push_back(mat[j][k]);

		sort(temp.begin(), temp.end());
                int cnt = 0;
                for(int j=i, k=0; j<m && k<n; ++j, ++k)
                        mat[j][k] = temp[cnt++];
	}

	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j)
			cout << mat[i][j] << "\t";
		cout << endl;
	}

	
}

int main(){

	// vector<vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
	vector<vector<int>> mat = {{11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}};
	cout << "Input matrix is: " << endl;
	for(auto &v: mat){
		for(auto &x: v)
			cout << x << " ";
		cout << endl;
	}
	cout << "Output matrix is: " << endl;
	solve(mat);
	cout << endl;
	return 0;
}
