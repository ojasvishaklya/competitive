// https://leetcode.com/problems/coin-change/

class Solution
{
public:
    int coin(vector<int> &coins, int tar, vector<int> &dp)
    {
        if (tar == 0)
        {
            return dp[tar] = 0;
        }

        if (dp[tar] != 0)
            return dp[tar];

        int ans = 1e8;
        for (int ele : coins)
        {
            if (tar - ele >= 0)
                ans = min(ans, coin(coins, tar - ele, dp));
        }
        return dp[tar] = ans + 1;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        int ans = coin(coins, amount, dp);
        return (ans < 1e8) ? ans : -1;
    }
};