#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] == true || grid[i][j] == 0)
        return 0;

    vis[i][j] = true;

    int up = dfs(grid, vis, i - 1, j, m, n);
    int down = dfs(grid, vis, i + 1, j, m, n);
    int left = dfs(grid, vis, i, j - 1, m, n);
    int right = dfs(grid, vis, i, j + 1, m, n);

    vis[i][j] = false;

    return grid[i][j] + max(up, max(down, max(left, right)));
}

int pathWithMaxSum(vector<vector<int>> grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ans = max(ans, dfs(grid, vis, i, j, m, n));
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    }
    cout << pathWithMaxSum(grid) << endl;

    return 0;
}