#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &LIS, vector<int> &arr)
{
    int ans = 1;

    for (int i = 0; i < LIS.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                LIS[i] = max(LIS[i], LIS[j] + 1);
        }
        ans = max(ans, LIS[i]);
    }

    return ans;
}

int lds(vector<int> &LDS, vector<int> &arr)
{
    int ans = 1;

    for (int i = LDS.size() - 1; i >= 0; i--)
    {
        for (int j = LDS.size() - 1; j > i; j--)
        {
            if (arr[i] > arr[j])
                LDS[i] = max(LDS[i], LDS[j] + 1);
        }
        ans = max(ans, LDS[i]);
    }

    return ans;
}
int main()
{
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = 8;
    vector<int> LIS(n, 1);
    vector<int> LDS(n, 1);

    int longestIncreasing = lis(LIS, arr);
    int longestDecreasing = lds(LDS, arr);

    int ans = max(longestDecreasing, longestIncreasing);

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, LIS[i] + LDS[i]);
    }

    cout << "Answer : " << ans - 1 << endl;

    for (int i = 0; i < n; i++)
    {
        cout << LIS[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << LDS[i] << " ";
    }
    cout << endl;

    return 0;
}