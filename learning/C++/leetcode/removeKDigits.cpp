#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;



string removeKDigits(string s, int k){
	stack<char> st;
	for(int i=0; i<s.size(); ++i){
		while(k>0 && !st.empty() && st.top()>s[i]){
			st.pop();
			--k;
		}
		st.push(s[i]);
	}


	while(k>0 && !st.empty()){
		st.pop();
		--k;
	}

	string result = "";
	while(!st.empty()){
		result.push_back(st.top());
		st.pop();
	}


	reverse(result.begin(), result.end());
	int i=0;
	while(i<result.size() && result[i]=='0')++i;

	result = result.substr(i);

	return result.empty() ? "0" : result;

}

int main(){
	
	cout << removeKDigits("10",2) << endl;
	return 0;
}