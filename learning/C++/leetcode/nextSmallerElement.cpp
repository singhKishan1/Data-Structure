#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nse(vector<int>&v){
	vector<int> result(v.size(), 0);
	stack<int> st;
	for(int i=v.size()-1; i>=0; --i){
		while(!st.empty() && st.top()>=v[i])st.pop();

		result[i] = st.empty() ? -1 : st.top();
		st.push(v[i]);
	}
	return result;
}

int main(){
	cout << "Enter range: ";
	int n;cin>>n;
	cout << "Enter element: ";
	vector<int>v(n);
	for(int i=0; i<n; ++i)cin>>v[i];

	auto result = nse(v);
	for(auto x:result){
		cout << x << " ";
	}cout << endl;

	return 0;
}