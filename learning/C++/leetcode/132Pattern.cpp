#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool solve(vector<int>&v){
	if(v.size()<3)return false;
	int n = v.size();
	
	stack<int> st;
	int third=INT32_MIN;
	for(int i=n-1; i>=0; --i){
		if(v[i]<third)return true;

		while(!st.empty() && st.top()<v[i]){
			third = st.top();
			st.pop();
		}
		st.push(v[i]);
	}
	return false;
	
}

int main(){
	cout << "Enter range:";
	int n;cin>>n;
	cout << "Enter element: ";
	vector<int> v(n);
	for(int i=0; i<n; ++i)cin>>v[i];

	cout << solve(v) << endl;
	return 0;
}