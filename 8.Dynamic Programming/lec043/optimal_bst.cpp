// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/

#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp.size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

vector<int> preSum;

int sum(vector<int> &arr, int si, int ei)
{
    return preSum[ei + 1] - preSum[si];
}


int dfs(vector<int> &arr, vector<vector<int>> &dp, int si, int ei)
{

    if (dp[si][ei] != 0)
        return dp[si][ei];

    int ans = 1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = cut == si ? 0 : dfs(arr, dp, si, cut - 1);
        int right = cut == ei ? 0 : dfs(arr, dp, cut + 1, ei);

        int small = left + sum(arr, si, ei) + right;

        if (small < ans)
            ans = small;
    }

    return dp[si][ei] = ans;
}

int main()
{
    vector<int> key = {10, 12, 20}, arr = {5, 10, 50};
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

    preSum.push_back(0);

    for (int i = 1; i < arr.size()+1; i++)
    {
        preSum.push_back(preSum[i - 1] + arr[i - 1]);
    }

    cout << dfs(arr, dp, 0, arr.size() - 1) << endl;

    display(dp);

    return 0;
}