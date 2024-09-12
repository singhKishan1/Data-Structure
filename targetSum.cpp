#include <iostream>
#include <vector>

using namespace std;

/**
 * Only backtracking
 */
int solve_1(vector<int> &v, int id, int sum, int target)
{
    if (sum == target && id >= v.size())
        return 1;
    if (id >= v.size())
        return 0;

    return solve_1(v, id + 1, sum + v[id], target) + solve_1(v, id + 1, sum - v[id], target);
}

/**
 * Backtracking with memoization
 */
int solve(vector<int> &v, int id, int sum, int totalSum, int target, vector<vector<int>> &dp)
{
    if (sum == target && id >= v.size())
        return 1;
    if (id >= v.size())
        return 0;

    if (dp[id][sum + totalSum] > 0)
        return dp[id][sum + totalSum];

    return dp[id][sum + totalSum] = solve(v, id + 1, sum - v[id], totalSum, target, dp) +
                                    solve(v, id + 1, sum + v[id], totalSum, target, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int targetSum;
    cin >> targetSum;

    int totalSum = 0;
    for (int i = 0; i < n; ++i)
        totalSum += v[i];

    cout << solve(v, 0, 0, totalSum, targetSum, dp) << endl;
    return 0;
}