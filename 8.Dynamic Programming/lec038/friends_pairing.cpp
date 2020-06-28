// https://www.geeksforgeeks.org/friends-pairing-problem/
#include <iostream>
#include <vector>
using namespace std;

int dfs(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = dfs(n - 1) + (n - 1) * dfs(n - 2);
}
int countFriendsPairings(int n)
{
    int dp[n + 1];

    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}
int main()
{

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 1, -1);
        cout << dfs(n, dp) << endl;
    }
    return 0;
}