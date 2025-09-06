#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;

void solve(string &str, int id, string exp, unordered_set<string> &ans, ll target, ll result, ll last){

	if(result==target && id==str.size()){
		ans.insert(exp);
		return;
	}

	if (id == str.size() || result > target)
	{
		return;
	}

	for (int i = id; i < str.size(); i++)
	{
		string curr = str.substr(id, i - id + 1);
		ll num = stoll(curr);
		if (id == 0)
		{
			solve(str, i + 1, exp + curr, ans, target, num, num);
		}
		else
		{
			solve(str, i + 1, exp + "+" + curr, ans, target, result + num, num);
			solve(str, i + 1, exp + "-" + curr, ans, target, result - num, -num);
			solve(str, i + 1, exp + "*" + curr, ans, target, result * num, last * num);
		}
		if (str[id] == '0')
			break;
	}
}

int main()
{
	string str = "1234";
	unordered_set<string> ans;
	solve(str, 0, "", ans, 10, 0, 0);
	for (auto s : ans)
		cout << s << endl;
	return 0;
}
