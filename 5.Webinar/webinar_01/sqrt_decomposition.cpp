#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> bucket, arr;
int bs = 0;

void update(int idx, int val)
{
    bucket[idx / bs] = bucket[idx / bs] - arr[idx] + val;
    arr[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;

    while (l % bs != 0 && l < r)
    {
        sum += arr[l++];
    }
    while (l + bs <= r)
    {
        sum += bucket[l / bs];
        l += bs;
    }

    while (l <= r)
    {
        sum += arr[l++];
    }
    return sum;
}

int main()
{
    

    int n=17;
    bs = (int)sqrt(n) + 1;

    bucket.resize(bs + 1, 0);

    arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    cout<<"Bucket Array : ";
    for (int i = 0; i < arr.size(); i++)
    {
        bucket[i / bs] += arr[i];

    }
    for (int i = 0; i < bucket.size(); i++)
        cout << bucket[i] << " ";
    //  update(3, 10); //paasing the value and index where thr update is required

    int leftLimit = 2;
    int rightLimit = 10;
    int ans = query(leftLimit, rightLimit);

    cout << endl
         << "Range Sum : " << ans;

    return 0;
}