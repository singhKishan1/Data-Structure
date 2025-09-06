#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

vector<int> solve(vector<int> v)
{

    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i & 1)
            odd.push_back(v[i]);
        else
            even.push_back(v[i]);
    }

    cout << "Printing idx odd elements: ";
    display(odd);
    cout << "Pring even idx elements: ";
    display(even);

    sort(odd.begin(), odd.end(), greater<int>());
    std::sort(even.begin(), even.end());

    cout << "Printing idx odd elements: ";
    display(odd);
    cout << "Pring even idx elements: ";
    display(even);

    vector<int> res;

    int x = 0, y = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i & 1)
            res.push_back(odd[y++]);
        else
            res.push_back(even[x++]);
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

    display(solve(v));
    return 0;
}