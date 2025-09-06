#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<vector<int>> &v){
	int n = v.size();
	for(int i=1; i<n; ++i){
		vector<int> temp;
		for(int j=i,k=0; j<n && k<n; ++j, ++k)
			temp.push_back(v[k][j]);
		sort(temp.begin(), temp.end());
		int cnt = 0;
		for(int j=i, k=0; j<n && k<n; ++j, ++k)
			v[k][j] = temp[cnt++];
	}
	for(int i=0; i<n; ++i){
		vector<int> temp;
		for(int j=i, k=0; j<n && k<n; ++j, ++k)
			temp.push_back(v[j][k]);
		sort(temp.begin(), temp.end(), greater<int>());
		int cnt = 0;
		for(int j=i, k=0; j<n && k<n; ++j, ++k)
			v[j][k] = temp[cnt++];
	}

	cout << "\n\nOutput: " << endl;
	for(auto &x: v){
		for(auto y: x)
			cout << y << "\t";
		cout << endl;
	}
}

int main(){
	vector<vector<int>> v = {{11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}, {39, 65, 55, 78, 52, 13}};
	cout << "Input: " << endl;
	for(auto &x: v){
		for(auto y: x)
			cout << y << "\t";
		cout << endl;
	}
	solve(v);
	cout << endl;
	return 0;
}
