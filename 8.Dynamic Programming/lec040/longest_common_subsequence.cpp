class Solution
{
public:
    int n;
    int m;
    int longestCommonSubsequence(string text1, string text2)
    {
        n = text1.size();
        m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dfs(text1, text2, 0, 0, dp);
    }

    int dfs(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == n || j == m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int count = 0;
        if (a[i] == b[j])
            count = dfs(a, b, i + 1, j + 1, dp) + 1;
        else
        {
            count = max(dfs(a, b, i + 1, j, dp), dfs(a, b, i, j + 1, dp));
        }

        return dp[i][j] = count;
    }
};