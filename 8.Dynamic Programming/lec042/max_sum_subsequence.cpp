// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

#include <iostream>
#include <vector>
using namespace std;

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

    vector<int> dp(n, 0);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {

            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += arr[i];
        ans = max(ans, dp[i]);
    }

    // for(int i=0 ;i<n;i++ )
    // cout<<dp[i]<<" ";

    // cout<<endl;

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