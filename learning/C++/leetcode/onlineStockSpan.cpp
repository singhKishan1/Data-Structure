#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner{
public:
	stack<pair<int, int>> st;
	int cnt = 0;

	StockSpanner(){};

	int next(int price){
		++cnt;
		int ans =0;

		while(!st.empty() && st.top().first<=price)st.pop();

		ans = st.empty() ? cnt : cnt - st.top().second;
		st.push({price, cnt});
		return ans;
	}
};

int main(){

	StockSpanner sp;
	vector<int> v;
	v.push_back(sp.next(100));
	v.push_back(sp.next(80));
	v.push_back(sp.next(60));
	v.push_back(sp.next(70));
	v.push_back(sp.next(60));
	v.push_back(sp.next(75));
	v.push_back(sp.next(85));


	cout << "Answer: ";
	for(auto x:v){
		cout << x << " ";
	}cout << endl;
	return 0;
}