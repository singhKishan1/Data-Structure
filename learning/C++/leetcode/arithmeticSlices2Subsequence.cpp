#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &v, int idx, vector<int> &op, int ans)
{

	if (idx >= v.size())
	{
		if (op.size() > 0)
			ans += op.size() * (op.size() + 1) / 2;

		return;
	}

	op.push_back(v[idx]);
	if(op.size()>2){
		if(op[1]-op[0]!=op[op.size()-1]-op[op.size()-2]){
			op.pop_back();
			return;
		}
	}

	for (int i = idx + 1; i < v.size(); ++i)
	{
		solve(v, i, op, ans);	
	}
	op.pop_back();
	return;
}

int arithmeticSlices(vector<int> &v)
{

	vector<int> op;
	int ans = 0;
	for (int i = 0; i < v.size() - 2; ++i)
		solve(v, i, op, ans);

	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cout << arithmeticSlices(v) << endl;
	return 0;
}
