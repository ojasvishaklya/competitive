// https://practice.geeksforgeeks.org/problems/gold-mine-problem

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int m;

int dfs(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &dp)
{
    if (c == m - 1)
    {
        return dp[r][c] = grid[r][c];
    }
    
    int a = INT_MIN;
    int b = INT_MIN;
    int z = INT_MIN;

    if (dp[r][c] != -1)
        return dp[r][c];
    if (r + 1 < n && c + 1 < m )
    {
        if (dp[r + 1][c + 1] == -1)
            dp[r + 1][c + 1] = dfs(grid, r + 1, c + 1, dp);
        a = dp[r + 1][c + 1];
    }
    if (r - 1 >= 0 && c + 1 < m)
    {
        if (dp[r - 1][c + 1] == -1)
            dp[r - 1][c + 1] = dfs(grid, r - 1, c + 1, dp);
        z = dp[r - 1][c + 1];
    }
    if (c + 1 < m )
    {
        if (dp[r][c + 1] == -1)
            dp[r][c + 1] = dfs(grid, r, c + 1, dp);
        b = dp[r][c + 1];
    }

    return dp[r][c] = max(max(a, b), z) + grid[r][c];
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int a;
                cin >> a;
                grid[i][j] = a;
            }
            int ans=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            {
                ans=max(ans, dfs(grid,i, 0, dp));
            }
        cout << ans<<endl;
    }
    return 0;
}