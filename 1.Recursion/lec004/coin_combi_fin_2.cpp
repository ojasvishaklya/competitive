#include <iostream>
#include <vector>

using namespace std;

int coin(vector<int> arr, int tar, string ans, int idx)
{

    if (tar == 0 || idx == arr.size())
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if (tar - arr[idx] >= 0)
    count += coin(arr, tar - arr[idx], ans + to_string(arr[idx]) + " ", idx + 1);
    count += coin(arr, tar, ans, idx + 1);

    return count;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    vector<int> vis(arr.size(), 0);
    int target = 10;
    cout << coin(arr, target, "", 0);
    return 0;
}