class Solution
{
public:
    int n;
    int m;
    int ans = INT_MIN;
    int maxDotProduct(vector<int> &a, vector<int> &b)
    {

        n = a.size();
        m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return dfs(a, b, dp, 0, 0);
    }

    int dfs(vector<int> &a, vector<int> &b, vector<vector<int>> &dp, int i, int j)
    {
        if (i == n || j == m)
        {
            return dp[i][j] = -1e8;
        }

        if (dp[i][j] != -1)
        {

            return dp[i][j];
        }

        int val = a[i] * b[j];
        int x = dfs(a, b, dp, i + 1, j + 1) + val;
        int y = dfs(a, b, dp, i, j + 1);
        int z = dfs(a, b, dp, i + 1, j);

        return dp[i][j] = max(max(x, y), max(val, z));
    }
};