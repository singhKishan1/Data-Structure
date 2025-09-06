#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nsr(vector<int> &v){
	int n = v.size();
	vector<int> ans(n,0);
	stack<pair<int, int>> st;
	for(int i=v.size()-1; i>=0; --i){
		if(st.size()==0)ans[i]=n;
		else {
			while(st.size()>0 && st.top().first>=v[i])st.pop();

			if(st.size()==0)ans[i] = n;
			else ans[i] = st.top().second;
		}
		st.push({v[i], i});
	}

	return ans;
}

vector<int> nsl(vector<int> &v){
	int n = v.size();
	vector<int> ans(n, 0);
	stack<pair<int, int>> st;
	for(int i=0; i<n; ++i){
		if(st.size()==0)ans[i] = -1;
		else {
			while(st.size()>0 && st.top().first>=v[i])st.pop();

			if(st.size()==0)ans[i] = -1;
			else ans[i] = st.top().second;
		}
		st.push({v[i], i});
	}
	return ans;
}

int largestRectangeInHistogram(vector<int> &v){
	int n = v.size();
	vector<int> right = nsr(v);
	vector<int> left = nsl(v);

	cout << "nsr: ";
	for(auto x:right)cout << x << " ";
	cout << endl;
	cout << "nsl: ";
	for(auto x:left) cout << x << " ";
	cout << endl;


	int ans = INT32_MIN;
	for(int i=0; i<n; ++i){
		ans = max(ans, (right[i]-left[i]-1)*v[i]);
	}
	return ans;
}

int main(){
	// cout << "Enter range:";
	// int n;cin>>n;
	// cout << "Enter values: ";
	// vector<int> v(n);
	// for(int i=0; i<n; ++i)cin>>v[i];

	vector<int> v= {2,1,5,6,2,3};

	cout << largestRectangeInHistogram(v) << endl;
	return 0;
}