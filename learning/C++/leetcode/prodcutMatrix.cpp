#include <iostream>
#include <vector>

using namespace std;

/*Unsigned long integer who can store large positive integer*/
typedef unsigned long long ll;

/*Function is for dispaying the grid's element*/
void display(vector<vector<int>> grid)
{

    cout << "\nDisplaying grid's data: \n";
    for (int r = 0; r < grid.size(); ++r)
    {
        for (int c = 0; c < grid[r].size(); ++c)
        {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}

/*This solution is based on O(1) space-complexity*/
vector<vector<int>> constructProductMatrixWithOof1(vector<vector<int>> grid)
{
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> ans(rows, vector<int>(cols));
    int MOD = 12345;
    ll pd = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            ans[i][j] = pd;
            grid[i][j] %= MOD;
            pd *= grid[i][j];
            pd %= MOD;
        }
    }

    pd = 1;
    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            int temp = grid[i][j];
            grid[i][j] = pd;
            pd *= temp;
            pd %= MOD;
        }
    }

    display(ans);
    display(grid);

    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            ans[i][j] = (ans[i][j]*grid[i][j])%MOD;
        }
    }

    return ans;;
}

/*This solution  is based on O(n) space-complexitiy*/
vector<vector<int>> constructProductMatrix(vector<vector<int>> grid)
{
    int rows = grid.size(), cols = grid[0].size();
    int MOD = 12345;

    vector<vector<int>> res(rows, vector<int>(cols));
    vector<vector<int>> suffArr(rows, vector<int>(cols));
    vector<vector<int>> preffArr(rows, vector<int>(cols));

    ll pd = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            preffArr[i][j] = pd;
            pd = grid[i][j] * pd;
            pd = pd % MOD;
        }
    }

    pd = 1;
    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = cols - 1; j >= 0; --j)
        {
            suffArr[i][j] = pd;
            pd = pd * grid[i][j];
            pd = pd % MOD;
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            res[i][j] = (preffArr[i][j] * suffArr[i][j]) % MOD;
        }
    }

    return res;
}

/*Main method where to program start executing*/
int main()
{
    vector<vector<int>> grid;
    int n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;

    cout << "Enter elements in array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        vector<int> v(m);
        for (int j = 0; j < m; ++j)
            cin >> v[j];

        grid.push_back(v);
    }

    display(constructProductMatrixWithOof1(grid));

    return 0;
}