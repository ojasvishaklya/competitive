#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void display(unordered_map<int, int> &dp)
{
    for (auto e : dp)
    {
        cout << e.first << "->" << e.second << endl;
    }
}

int coin_change(int target, vector<int> &arr, int idx, string ans, unordered_map<int, int> &dp)
{
    if (idx == arr.size())
    {
        if (target == 0)
        {
            cout << ans << endl;
            return dp[target] = 1;
        }
        return 0;
    }

    if (dp[target] != 0)
        return dp[target];
    int count = 0;

    if (target - arr[idx] >= 0)
    {
        count += coin_change(target - arr[idx], arr, idx, ans + to_string(arr[idx]) + " ", dp);
    }
    count += coin_change(target, arr, idx + 1, ans, dp);

    return dp[target] = count;
}

int main()
{

    unordered_map<int, int> dp;

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 10;
    cout << coin_change(target, arr, 0, "", dp);
    cout << endl;
    display(dp);
    return 0;
}