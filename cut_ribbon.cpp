#include <bits/stdc++.h>
using namespace std;

int t[4001][4001];
int solve(vector<int> v, int n, int cnt, int w)
{
    if (w == 0)
        return cnt;

    if (n == 0)
        return 0;

    if (t[cnt][w] != -1)
        return t[cnt][w];

    if (v[n - 1] <= w)
        return t[cnt][w] = max(solve(v, n, cnt + 1, w - v[n - 1]), solve(v, n - 1, cnt, w));
    else
        return t[cnt][w] = solve(v, n - 1, cnt, w);
}

int main()
{
    memset(t, -1, sizeof(t));
    int w;
    cin >> w;
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    cout << solve(v, 3, 0, w) << endl;
    return 0;
}
