#include <iostream>
#include <vector>

using namespace std;

int coin(vector<int> &arr, int target, int idx, vector<vector<int>> &dp)
{

    if (target == 0 || idx == arr.size())
    {
        if (target == 0)
        {
            return dp[idx][target] = 1;
        }
        return dp[idx][target] = 0;
    }

    if (dp[idx][target] != 0)
        return dp[idx][target];
    int count = 0;

    if (target - arr[idx] >= 0)
        count += coin(arr, target - arr[idx], idx + 1, dp);
    count += coin(arr, target, idx + 1, dp);

    return dp[idx][target] = count;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int target = 10;

    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, 0));
    cout << coin(arr, target, 0, dp) << endl;

    for (int i = 0; i <= arr.size(); i++)
    {
        for (int j = 0; j < target + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}