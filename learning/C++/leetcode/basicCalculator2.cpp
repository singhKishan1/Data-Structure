#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

/**
 *

int prec(char ch){
	if(ch=='/' || ch=='*')return 2;
	return 1;
}

int solve(string &s){
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	cout << "string : " << s << endl;
	stack<int> st;
	stack<char> op;
	string num = "";
	for(int i=0; i<s.size(); ++i){
		char ch = s[i];
		if(isdigit(ch))
			num.push_back(ch);
		else{
			if(num.size()>0){
				st.push(stoi(num));
				num = "";
			}

			if(op.empty() || (!op.empty() && prec(op.top())<prec(ch))){
				op.push(ch);
			}else{
				while(!op.empty() && prec(op.top())>=prec(ch)){

					int num2 = st.top(); st.pop();
					int num1 = 0;
					if(st.size()>0) num1 = st.top(); st.pop();

					char c = op.top(); op.pop();
					if(c=='+'){
						st.push(num1+num2);
					}else if(c=='-'){
						st.push(num1-num2);
					}else if(c=='*'){
						st.push(num1*num2);
					}else if(c=='/'){
						st.push(num1/num2);
					}


				}

				op.push(ch);
			}
		}
	}

	if(num.size()>0)
		st.push(stoi(num));

	while(!op.empty()){
		int num2 = st.top(); st.pop();
		int num1 = 0;
		if(st.size()>0){
			num1 = st.top();
			st.pop();
		}

		char c = op.top(); op.pop();
		if(c=='+')
			st.push(num1+num2);
		else if(c=='-')
			st.push(num1-num2);
		else if(c=='*')
			st.push(num1*num2);
		else if(c=='/')
			st.push(num1/num2);
	}

	return st.top();
}

 */


int solve(string &s){
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	stack<int> st;
	char sign = '+';
	int num = 0;

	for(int i=0; i<s.size(); ++i){
		char ch = s[i];
		if(isdigit(ch))
			num = num * 10 + (ch - '0');
		if(!isdigit(ch) || i == s.size()-1){
			
			if(sign=='+')
				st.push(num);
			else if(sign=='-')
				st.push(-num);
			else if(sign=='*'){
				int val = st.top(); st.pop();
				st.push(val * num);
			}else if(sign=='/'){
				int val = st.top(); st.pop();
				st.push(val/num);
			}

			sign = ch;
			num = 0;
		
		}
	}

	int result = 0;
	while(!st.empty()){
		result += st.top();
		st.pop();
	}
	return result;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << solve(s) << endl;
	}
	return 0;
}
