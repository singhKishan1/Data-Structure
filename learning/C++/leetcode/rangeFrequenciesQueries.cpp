#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



void rangeFrequenciesQueries(vector<int> &v)
{
	int n = v.size();
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < v.size(); ++i)
	{
		mp[v[i]].push_back(i);
	}

	// print map
	cout << "Map is: " << endl;
	for (auto x : mp)
	{
		cout << x.first << " : ";
		for (auto y : x.second)
		{
			cout << y << " ";
		}
		cout << endl;
	}

	bool isQuery = true;
	while (isQuery)
	{
		cout << "Enter ranges and values: ";
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];

		int ans = upper_bound(mp[arr[2]].begin(), mp[arr[2]].end(), arr[1]) - lower_bound(mp[arr[2]].begin(), mp[arr[2]].end(), arr[0]);
		cout << "Answer is: " << ans << endl;
		cout << "Wanted to extra query :";
		cin >> isQuery;
	}
	cout << endl;
}

int main()
{

	vector<int> v = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
	rangeFrequenciesQueries(v);
	return 0;
}
