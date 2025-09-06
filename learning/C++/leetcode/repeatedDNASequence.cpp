#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> solve(string s)
{
    if (s.size() < 10)
        return {};

    unordered_set<string> seen, result;
    for (int i = 0; i <= s.size() - 10; ++i)
    {
        string sub = s.substr(i, 10);
        if (seen.find(sub) != seen.end())
        {
            result.insert(sub);
        }

        seen.insert(sub);
    }

    return vector<string>(result.begin(), result.end());
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans = solve(s);
    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}