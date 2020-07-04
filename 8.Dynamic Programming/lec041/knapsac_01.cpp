#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> &weight, vector<int> &amount, int target, int idx, vector<vector<int>> &dp)
{

    if (idx == weight.size() || target == 0)
        return 0;

    if (dp[idx][target] != 0)
        return dp[idx][target];

    int ans = -1e8;

    if (target - weight[idx] >= 0)
        ans = max(ans, dfs(weight, amount, target - weight[idx], idx + 1, dp) + amount[idx]);
    ans = max(ans, dfs(weight, amount, target, idx + 1, dp));

    return dp[idx][target] = ans;
}

void knapsac()
{

    vector<int> weight;
    vector<int> amount;
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        amount.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        weight.push_back(a);
    }

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    cout << dfs(weight, amount, w, 0, dp) << endl;
    return;
}
int main()
{

    int t;
    cin >> t;

    while (t-- > 0)
    {
        knapsac();
    }
    return 0;
}