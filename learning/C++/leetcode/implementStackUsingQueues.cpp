#include <iostream>
#include <queue>


using namespace std;


class MyStack{
public:
	queue<int> q1, q2;

	MyStack(){}

	void push(int val){
		q1.push(val);
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}

		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}

	}

	int pop(){
		int val = q2.front();
		q2.pop();
		return val;
	}

	int top(){
		return q2.front();
	}

	bool empty(){
		return q2.empty();
	}
};

int main(){

}