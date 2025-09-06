#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pd;

/*****
 * kya be
 */
ll solve(vector<int> v1, vector<int> v2, int k)
{
    int n = v1.size();
    vector<pd> p;
    for (int i = 0; i < n; ++i)
        p.push_back({v1[i], v2[i]});
}

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i)
        cin >> v1[i];
    for (int i = 0; i < n; ++i)
        cin >> v2[i];

    int k;
    cin >> k;
    cout << solve(v1, v2, k) << endl;
    return 0;
}