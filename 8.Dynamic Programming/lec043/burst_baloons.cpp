// https://leetcode.com/problems/burst-balloons/

class Solution
{
public:
    int maxCoins(vector<int> &arr)
    {
        if (!arr.size())
            return 0;
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        return dfs(arr, dp, 0, arr.size() - 1);
    }

    int dfs(vector<int> &arr, vector<vector<int>> &dp, int si, int ei)
    {
        if (dp[si][ei] != 0)
            return dp[si][ei];

        int lt = si == 0 ? 1 : arr[si - 1];
        int rt = ei == arr.size() - 1 ? 1 : arr[ei + 1];

        int ans = 0;

        for (int cut = si; cut <= ei; cut++)
        {
            int left = cut == si ? 0 : dfs(arr, dp, si, cut - 1);
            int right = cut == ei ? 0 : dfs(arr, dp, cut + 1, ei);

            int small = left + lt * arr[cut] * rt + right;

            if (small > ans)
                ans = small;
        }

        return dp[si][ei] = ans;
    }
};