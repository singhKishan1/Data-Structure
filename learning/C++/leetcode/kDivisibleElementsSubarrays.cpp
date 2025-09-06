#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(vector<int> v, int k, int p){
	int cnt = 0;
	int j=0,n=v.size();
	set<vector<int>> st;
	vector<int> a;
	while(j<n){
		if(v[j]%p==0)++cnt;

		a.push_back(v[j]);
		while(cnt>k && a.size()>0){
			if(a[0]%p==0)--cnt;
			a.erase(a.begin());
		}

		if(cnt<=k && a.size()>0)
			st.insert(a);
		++j;
	}

	// printing value set of array.
	for(auto x:st){
		for(auto y:x)
			cout << y <<  "\t";
		cout <<endl;
	}

	return st.size();
}	

int main(){
	int n,k,p;
	cin>>n>>k>>p;
	vector<int> v(n);
	for(int i=0; i<n; ++i)cin>>v[i];
	cout << solve(v,k,p) << endl;
	return 0;
}
