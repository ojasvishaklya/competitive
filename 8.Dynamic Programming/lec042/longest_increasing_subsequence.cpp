// https://leetcode.com/problems/longest-increasing-subsequence/

// LIS : ye khud pe khatam hone vala longest increasing subsequence dega
// LDS : ye khud pe khatam hone vala longest decreasing subsequence dega

class Solution
{
public:
    int lengthOfLIS(vector<int> &arr)
    {

        int n = arr.size();
        if (!n)
            return 0;
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};