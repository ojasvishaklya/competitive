#include <iostream>
#include <vector>

using namespace std;

int coin(vector<int> arr, int tar, string ans, int idx, vector<int> vis)
{

    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0 && vis[i] == 0)
        {
            vis[i] = 1;
            count += coin(arr, tar - arr[i], ans + to_string(arr[i]) + " ", i, vis);
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
    cout << coin(arr, target, "", 0, vis);
    return 0;
}