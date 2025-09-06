#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solve(vector<string> &v){
	stack<int> st;
	for(int i=0; i<v.size(); ++i){
		string s = v[i];
		if(s=="*" || s=="/" || s=="+" || s=="-"){
			int num2 = st.top(); st.pop();
			int num1 = 0;
			if(st.size()>0){
				num1 = st.top();
				st.pop();
			}

			if(s=="*")
				st.push(num1*num2);
			else if(s=="/")
				st.push(num1/num2);
			else if(s=="+")
				st.push(num1+num2);
			else if(s=="-")
				st.push(num1-num2);

		}else{
			st.push(stoi(s));
		}
	}

	return st.top();
}

int main(){
	// vector<string> v = {"2", "1", "+", "3", "*"};
	// vector<string> v = {"4", "13", "5", "/", "+"};
	vector<string> v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << solve(v) << endl;
	return 0;
}
