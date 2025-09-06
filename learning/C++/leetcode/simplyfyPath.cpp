#include <bits/stdc++.h>

using namespace std;

string solve(string s){
	vector<string> v;
	stringstream ss(s);
	string token;
	while(getline(ss, token, '/')){
		if(token=="" || token==".") continue;
		else if(token==".."){
			if(!v.empty())v.pop_back();
		}
		else v.push_back(token);		
	}

	string result="/";
	for(int i=0; i<v.size(); ++i){
		result += v[i];
		if(i<v.size()-1)
			result += "/";
	}
	return result;	
}

int main(){
	string s;cin>>s;
	cout << solve(s) << endl;
	return 0;
}
