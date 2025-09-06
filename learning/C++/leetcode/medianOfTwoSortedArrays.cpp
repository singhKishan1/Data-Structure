#include <iostream>
#include <vector>
using namespace std;

double solve(vector<int> &v1, vector<int> &v2)
{
    int n = v1.size(), m = v2.size();
    vector<int> a;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            a.push_back(v1[i]);
            ++i;
        }
        else
        {
            a.push_back(v2[j]);
            ++j;
        }

        if (a.size() == (n + m) / 2)
        {
            if ((n + m) % 2 == 0)
            {
                if (i < n && j < m)
                {
                    if (v1[i] < v2[j])
                    {
                        a.push_back(v1[i]);
                    }
                    else
                    {
                        a.push_back(v2[j]);
                    }
                }
                else if (i < n)
                {
                    a.push_back(v1[i]);
                }
                else if (j < m)
                {
                    a.push_back(v2[j]);
                }

                return (double)(a[a.size() - 1] + a[a.size() - 2]) / 2;
            }
            else
            {
                return (double)a[a.size() - 1];
            }
        }
    }

    while (i < n)
    {
        a.push_back(v1[i]);
        ++i;
        if (a.size() == (n + m) / 2)
        {
            if ((n + m) % 2 == 0)
            {
                if (i < n)
                    a.push_back(v1[i]);

                return (double)(a[a.size() - 1] + a[a.size() - 2]) / 2;
            }
            else
            {
                return (double)a[a.size() - 1];
            }
        }
    }

    while (j < m)
    {
        a.push_back(v2[j]);
        ++j;
        if (a.size() == (n + m) / 2)
        {
            if ((n + m) % 2 == 0)
            {
                if (i < n)
                    a.push_back(v2[i]);

                return (double)(a[a.size() - 1] + a[a.size() - 2]) / 2;
            }
            else
            {
                return (double)a[a.size() - 1];
            }
        }
    }

    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; ++i)
        cin >> v1[i];
    for (int i = 0; i < m; ++i)
        cin >> v2[i];

    cout << solve(v1, v2) << endl;
    return 0;
}