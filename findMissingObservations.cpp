#include <iostream>
#include <vector>

using namespace std;

vector<int> solve(vector<int> &rolls, int mean, int n)
{
    int sum = 0;
    for (int i = 0; i < rolls.size(); ++i)
        sum += rolls[i];

    int rms = mean * (n + rolls.size()) - sum;
    if (rms > 6 * n || rms < n)
        return {};

    int distributedMean = rms / n;
    int mod = rms % n;
    vector<int> ans(n, distributedMean);
    for (int i = 0; i < mod; ++i)
        ans[i]++;
    return ans;
}

int main()
{

    int sum;
    cin >> sum;

    vector<int> v;
    int n;
    cin >> n;
    vector<int> temp = solve(v, sum, n);

    // print.
    for (auto x : temp)
        cout << x << " ";
    cout << endl;
    return 0;
}