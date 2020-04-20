#include <iostream>
#include <vector>

using namespace std;

int coin(vector<int> arr, int tar, string ans)
{

    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
            count += coin(arr, tar - arr[i], ans + to_string(arr[i]) + " ");
    }

    return count;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int target=10;
    cout << coin(arr, target, "");
    return 0;
}