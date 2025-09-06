#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ans = 0;

vector<vector<int>> arr;
void solve(vector<int> &v, int id, int sum, int k)
{
    if (id >= v.size()){
        if(sum==k)++ans;
        return;
    }

    solve(v, id+1, sum|v[id], k);
    solve(v, id+1, sum, k);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int k = 0;
    for (int i = 0; i < n; ++i)
        k = k | v[i];

    // for (int i = 0; i < v.size(); ++i)
    // {
        solve(v, 0, 0, k);
    // }

    cout << ans << endl;
    return 0;
}