#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef long long ll;

ll solve(vector<int> &v, int k){
	ll ans = 0, sum = 0;
	int i=0, j=0, n = v.size();
	unordered_set<int> st;
	while(j<n){
		while(i<=j && st.find(v[j])!=st.end()){
			st.erase(v[i]);
			sum -= v[i];
			++i;
		}

		st.insert(v[j]);
		sum += v[j];
		++j;
		if(st.size()==k){
			ans = max(ans, sum);
			st.erase(v[i]);
			sum -= v[i];
			++i;
		}

	}

	return ans;p
	
}

int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; ++i)cin>>v[i];
	int k;cin>>k;
	cout << solve(v, k) << endl;
	return 0;
}
