#include <iostream>
#include <vector>
using namespace std;

int solve(vector<string> v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == "++X" || v[i] == "X++")
            ans += 1;
        else
            ans -= 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cout << solve(v) << endl;
    return 0;
}