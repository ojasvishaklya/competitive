https://leetcode.com/problems/target-sum/

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {

        vector<vector<int>> dp(nums.size() + 1, vector<int>(2001, -1));
        return dfs(nums, S, dp, 0, 0);
    }

    int dfs(vector<int> &nums, int sum, vector<vector<int>> &dp, int idx, int tar)
    {
        if (idx == nums.size())
        {
            if (tar == sum)
            {
                return dp[idx][tar + 1000] = 1;
            }
            return 0;
        }

        if (dp[idx][tar + 1000] != -1)
            return dp[idx][tar + 1000];

        int add = dfs(nums, sum, dp, idx + 1, tar - nums[idx]);
        int sub = dfs(nums, sum, dp, idx + 1, tar + nums[idx]);
        return dp[idx][tar + 1000] = add + sub;
    }
};