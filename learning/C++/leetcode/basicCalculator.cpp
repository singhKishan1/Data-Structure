#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

/*
int solve(string &s, int &i){
	cout << s << endl;
	stack<int> st;
	stack<char> op;
	string num="";
	while(i<s.size()){
		if(s[i]>='0' && s[i]<='9'){
			num.push_back(s[i]);
			++i;

		}else if(s[i]=='-' || s[i]=='+'){
			if(num.size()>0)st.push(stoi(num));
			num = "";
			op.push(s[i]);
			++i;
		}else if(s[i]=='('){
			++i;
			if(num.size()>=0)
				st.push(stoi(num));
			num = "";
			st.push(solve(s, i));
		}else if(s[i]==')'){
			++i;
			break;

		}
	}

	if(num.size()>0)
		st.push(stoi(num));

	// cout << st.size() << endl;
	// performing mathematic operations
	while(st.size()>1){
		int num2 = st.top(); st.pop();
		int num1 = 0;
		if(st.size()>0){
			num1 = st.top(); st.pop();
		}

		char ch = op.top(); op.pop();
		if(ch=='-')
			st.push(num2-num1);
		else if(ch=='+')
			st.push(num2+num1);
	}

e 	// returning calucalated result...
	return st.top();

}
*/

/**
 *
int solve(string &s, int &i){
	stack<int> st;
	string num = "";
	stack<char> op;
	for(; i<s.size();){
		if(s[i]>='0' && s[i]<='9'){
			num.push_back(s[i]);
			++i;
		}else if(s[i]=='+' || s[i]=='-'){
			if(num.size()>0){
				st.push(stoi(num));
				num = "";
			}

			if(op.size()>0){
				char ch = op.top(); op.pop();

				int num2 = st.top(); st.pop();
				int num1 = 0;
				if(st.size()>0){
					num1 = st.top(); st.pop();
				}

				if(ch == '-')
					st.push(num1-num2);
				else if(ch == '+')
					st.push(num1 + num2);

				op.push(s[i]);
			}else{
				op.push(s[i]);
			}
			++i;
		}else if(s[i]=='('){
			++i;
			st.push(solve(s, i));
		}else if(s[i]==')'){
			++i;
			break;
		}
	}

	if(num.size()>0){
		st.push(stoi(num));
		num = "";
	}

	if(op.size()>0){
		char ch = op.top(); op.pop();
		int num2 = st.top(); st.pop();
		int num1 = 0;
		if(st.size()>0){
			num1 = st.top(); st.pop();
		}

		if(ch == '-')
			st.push(num1-num2);
		else if(ch=='+')
			st.push(num1+num2);
	}

	return st.top();
}

*
**/

int solve(string &s, int &i)
{
	stack<int> st;
	char sign = '+';
	int num = 0;
	for (; i < s.size(); ++i)
	{
		char ch = s[i];
		if (isdigit(ch))
			num = num * 10 + (ch - '0');

		if (ch == '(')
		{
			++i;
			num = solve(s, i);
		}

		if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1)
		{
			if (sign == '+')
				st.push(num);
			else if (sign == '-')
				st.push(-num);

			num = 0;
			sign = ch;

			if (ch == ')')
				break;
		}
	}

	int result = 0;
	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	cout << "Result: " << result << endl;
	return result;
}

int basicCalculator(string s)
{
	int id = 0;
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	return solve(s, id);
}

int main()
{
	string s;
	getline(cin, s);
	cout << basicCalculator(s) << endl;
	return 0;
}
