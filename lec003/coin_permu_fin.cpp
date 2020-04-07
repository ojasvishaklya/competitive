#include <iostream>
#include <vector>

using namespace std;

int coin(vector<int> arr, int t, string ans, vector<int> vis)
{
    if (t == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (t - arr[i] >= 0 && vis[i] == 0)
        {
            vis[i] = 1;
            count += coin(arr, t - arr[i], ans + to_string(arr[i]) + " ", vis);
            vis[i] = 0;
        }
    }

    return count;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    vector<int> vis(arr.size(), 0);
    int target = 10;
    cout << coin(arr, target, "", vis);
    return 0;
}