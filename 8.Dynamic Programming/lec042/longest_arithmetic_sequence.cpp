// https://leetcode.com/problems/longest-arithmetic-sequence/

class Solution
{
public:
    int longestArithSeqLength(vector<int> &arr)
    {

        unordered_map<int, int> dp[arr.size()];
        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i][arr[i] - arr[j]] = dp[j][arr[i] - arr[j]] + 1;
                ans = max(ans, dp[i][arr[i] - arr[j]]);
            }
        }

        return ans + 1;
    }
};