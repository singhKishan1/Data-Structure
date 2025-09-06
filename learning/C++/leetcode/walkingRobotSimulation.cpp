#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solve(vector<int> &v, vector<vector<int>> &ob)
{
    unordered_set<string> st;
    vector<vector<int>> ds = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < ob.size(); ++i)
        st.insert(to_string(ob[i][0]) + "#" + to_string(ob[i][1]));

    int res = 0, dir = 0, x = 0, y = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == -1)
            ++dir;
        else if (v[i] == -2)
            --dir;
        else
        {
            for (int j = 0; j < v[i]; ++j)
            {
                string pos = to_string(x + ds[dir][0]) + "#" + to_string(y + ds[dir][1]);
                if (st.find(pos) != st.end())
                    break;

                x += ds[dir][0];
                y += ds[dir][1];
            }

            res = max(res, x * x + y * y);
        }

        if (dir < 0)
            dir = 3;
        else if (dir > 3)
            dir = 0;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int m;
    cin>>m;
    vector<vector<int>> ob(m, vector<int>(2, 0));
    for (int i = 0; i < m; ++i)
    {
        cin >> ob[i][0] >> ob[i][1];
    }

    cout << solve(v, ob) << endl;
    return 0;
}