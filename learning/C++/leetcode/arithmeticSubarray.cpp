#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool solve(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return false;
    sort(arr.begin(), arr.end());
    int i = 0, j = 0;
    while (j < n)
    {
        if (j - i + 1 >= 3)
        {
            if (arr[i + 1] - arr[i] != arr[j] - arr[j - 1])
                return false;
        }
    }

    return true;
}

vector<bool> arithmeticSubarray(vector<int> &arr, vector<int> l, vector<int> r)
{
    int n = arr.size();

    vector<bool> ans;
    int m = l.size();
    for (int i = 0; i < m; ++i)
    {
        vector<int> subarray(arr.begin() + l[i], arr.begin() + r[i] + 1);
        ans.push_back(solve(subarray));
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int m;
    cin >> m;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; ++i)
        cin >> l[i] >> r[i];

    vector<bool> result_of_arithmeticSubarray = arithmeticSubarray(arr, l, r);
    for (bool res : result_of_arithmeticSubarray)
    {
        cout << (res ? "true" : "false") << endl;
    }

    return 0;
}