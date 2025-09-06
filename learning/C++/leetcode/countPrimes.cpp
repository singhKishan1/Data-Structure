#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solve(int n){
	
	vector<bool> v(n+1,false);
	for(int i=2; i*i<=n;){
		for(int j=2; j*i<=n; ++j){
			v[j*i]=true;	
		}

		int j=i+1;
		while(j<=n && v[j]==true)++j;

		i = j;
	}

	int cnt= 0;
	for(int i=2; i<v.size(); ++i){
		if(v[i]==false){
			++cnt;
			cout << i  << "\t";
		}
	}

	return cnt;

}

int main(){
	int n;
	cin>>n;
	cout << solve(n) << endl;
	return  0;
}
