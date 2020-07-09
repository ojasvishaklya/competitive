#include <iostream>
#include <vector>

using namespace std;

int MCM(vector<int> &arr, vector<vector<int>> &dp, int si, int ei)
{
    if (si + 1 == ei)
    {
        return 0;
    }

    if (dp[si][ei] != 0)
        return dp[si][ei];

    int ans = 1e8;

    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = MCM(arr, dp, si, cut);
        int right = MCM(arr, dp, cut, ei);

        int smallAns = left + arr[si] * arr[cut] * arr[ei] + right;

        if (smallAns < ans)
            ans = smallAns;
    }

    return dp[si][ei] = ans;
}

int MCM_DP(vector<int> &arr, vector<vector<int>> &dp, int si, int ei)
{
    for (int gap = 2; gap < dp.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < dp.size(); si++, ei++)
        {
            if (si + 1 == ei)
            {
                continue;
            }

            int ans = 1e8;

            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];  //MCM(arr, dp, si, cut);
                int right = dp[cut][ei]; // MCM(arr, dp, cut, ei);

                int smallAns = left + arr[si] * arr[cut] * arr[ei] + right;

                if (smallAns < ans)
                    ans = smallAns;
            }

            dp[si][ei] = ans;
        }
    }

    return dp[0][arr.size() - 1];
}
int main()
{
    vector<int> arr = {2, 3, 10, 5, 4};
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

    MCM_DP(arr, dp, 0, arr.size() - 1);

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp.size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}