// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

#include <iostream>
#include <vector>
using namespace std;

void increasing(vector<int> &arr, vector<int> &dp)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += arr[i];
    }
}

void decreasing(vector<int> &arr, vector<int> &dp)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += arr[i];
    }
}

void helper()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    vector<int> inc(n, 0);
    vector<int> dec(n, 0);

    int ans = 0;
    increasing(arr, inc);
    decreasing(arr, dec);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, inc[i] + dec[i] - arr[i]);
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        helper();
    }
    return 0;
}