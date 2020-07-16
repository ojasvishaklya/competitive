#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int a = arr[i];
    int b = arr[j];

    arr[j] = a;
    arr[i] = b;
}

void downHeapify(vector<int> &arr, int size, int idx)
{
    if (idx >= size)
        return;

    int max = idx;

    if (2 * idx + 1 < size && arr[2 * idx + 1] > arr[max])
        max = 2 * idx + 1;
    if (2 * idx + 2 < size && arr[2 * idx + 2] > arr[max])
        max = 2 * idx + 2;
    if (max != idx)
    {
        swap(arr, idx, max);
        downHeapify(arr, size, max);
    }
}

int main()
{
    vector<int> arr = {-4,0,7,4,9,-5,-1,0,-7,-1};

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    int n = arr.size();
    for (int i = arr.size() - 1; i >= 0; i--)
        downHeapify(arr, n, i);

    while (n != 0)
    {
        n--;
        swap(arr, 0, n);
        downHeapify(arr, n, 0);
    }

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}