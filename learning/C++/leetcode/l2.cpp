#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x : v)
        pq.push(x);

    vector<int> ans;
    while (pq.size() > 0)
    {
        int n = pq.top();
        pq.pop();

        if (pq.size() > 0)
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        ans.push_back(n);
    }

    return ans;
}

void display(vector<int> v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    display(solve(v));

    return 0;
}