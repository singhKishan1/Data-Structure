#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nge(vector<int> &v){
	vector<int> ans(v.size(), 0);
	stack<int> st;
	for(int i=v.size()-1; i>=0;  --i){
		if(st.size()==0)
			ans[i] = -1;
		else{
			while(st.size()>0 && st.top()<=v[i]){
				st.pop();
			}

			if(st.size()==0)
				ans[i] = -1;
			else
				ans[i] = st.top();
		}
		st.push(v[i]);
	}

	return ans;
}

vector<int> nextGreaterElement(vector<int>&v1, vector<int>&v2){
	vector<int> nge_result = nge(v2);
	unordered_map<int, int> mp;
	for(int i=0; i<v2.size(); ++i){
		mp[v2[i]] = i;
	}

	vector<int> result(v1.size(), 0);
	for(int i=0; i<v1.size(); ++i){
		if(mp.find(v1[i])!=mp.end()){
			result[i] = nge_result[mp[v1[i]]];
		}
	}

	return result;
}


int main(){
	cout << "enter range: ";
	int n;
	cin>>n;
	cout << "enter elment: ";
	vector<int> v(n);
	for(int i=0; i<n; ++i)cin>>v[i];


	auto ans = nge(v);
	for(auto x:ans){
		cout << x << " ";

	}
	cout << endl;
	return 0;
}