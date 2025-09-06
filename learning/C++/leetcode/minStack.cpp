#include <iostream>
#include <stack>

using namespace std;

class MinStack{
public:
	stack<int> s1, s2;

	MinStack(){}

	void push(int val){
		s1.push(val);
		if(s2.empty())s2.push(val);
		else if(s2.top()>=val)s2.push(val);
	}

	void pop(){
		if(!s1.empty() && s1.top()==s2.top()){
			s1.pop();
			s2.pop();
		}else s1.pop();
	}

	int top(){
		s1.top();
	}

	int getMin(){
		return s2.top();
	}
}

int main(){

	return 0;
}