#include <iostream>
#include <stack>


using namespace std;


bool validParenthesis(string str){
	stack<char> st;
	for(char ch: str){
		if(st.size()==0 && (ch==']' || ch=='}' || ch==')'))return false;
		else if(ch=='(' || ch=='{' || ch=='['){
			st.push(ch);
		}else if(st.size()>0){
			if(ch==')' && st.top()=='('){
				st.pop();
			}else if(ch=='}' && st.top()=='{'){
				st.pop();
			}else if(ch==']' && st.top()=='['){
				st.pop();
			}else{
				return false;
			}
		}
	}
	return st.size()==0;
}

int main(){
	cout<<"enter value:";
	string str;cin>>str;
	cout << "Answer: " << validParenthesis(str) << endl;
	return 0;
}