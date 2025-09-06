#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockSpanProblem(vector<int>&v){
	stack<pair<int, int>> st;
	vector<int> result(v.size(), 0);
	for(int i=0; i<v.size(); ++i){
		if(st.size()==0){
			result[i] = i+1;
		}else{
			while(st.size()>0 && st.top().first<=v[i])st.pop();

			if(st.size()==0)
				result[i] = i+1;
			else{
				result[i] = i - st.top().second;
			}
		}
		st.push({v[i], i});
	}

	return  result;
}

int main(){
	cout << "Enter range:";
	int n;cin>>n;
	cout << "Enter value: ";
	vector<int>v(n);
	for(int i=0; i<n; ++i)cin>>v[i];

	cout << "Result: ";
	auto result = stockSpanProblem(v);
	for(auto x:result)cout << x << " ";
	cout << endl;
	return 0;
}