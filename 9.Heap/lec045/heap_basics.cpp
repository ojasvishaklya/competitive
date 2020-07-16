#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &arr)
{
    cout << "-------------------------------" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        string leftEle = "null";
        string rightEle = "null";

        if (2 * i + 1 < arr.size())
            leftEle = to_string(arr[2 * i + 1]);

        if (2 * i + 2 < arr.size())
            rightEle = to_string(arr[2 * i + 2]);

        cout << leftEle << " <- " << arr[i] << " -> " << rightEle << endl;
    }
}

int height(vector<int> &arr, int idx)
{
    if (idx >= arr.size())
        return 0;

    int left = height(arr, 2 * idx + 1);
    int right = height(arr, 2 * idx + 2);

    return max(left, right) + 1;
}

void swap(vector<int> &arr, int i, int j)
{
    int a = arr[i];
    int b = arr[j];

    arr[j] = a;
    arr[i] = b;
}

void downHeapify_(vector<int> &arr, int idx)
{
    if (idx >= arr.size())
        return;

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int max = idx;

    if (2 * idx + 1 < arr.size() && arr[left] > arr[max])
        max = left;

    if (2 * idx + 2 < arr.size() && arr[right] > arr[max])
        max = right;

    if (max != idx)
    {
        swap(arr, idx, max);
        downHeapify_(arr, max);
    }
}
void downHeapify(vector<int> &arr)
{
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        downHeapify_(arr, i);
    }
}
void upHeapify(vector<int> &arr, int idx)
{
    int parent = (idx - 1) / 2;

    int min = idx;
    if (parent >= 0 && arr[parent] < arr[idx])
        min = parent;

    if (min != idx)
    {
        swap(arr, idx, min);
        upHeapify(arr, min);
    }
}

void push(vector<int> &arr, int val)
{
    arr.push_back(val);
    upHeapify(arr,arr.size()-1);
}


void pop(vector<int> &arr)
{
    swap(arr,0,arr.size()-1);
    arr.pop_back();
    downHeapify(arr);
}


int main()
{
    vector<int> arr = {0, 30, 50, 10, 100, 20, 50, 80, 60};
    cout << height(arr, 0) << endl;
    display(arr);
    downHeapify(arr);
    display(arr);
    push(arr,110);
    display(arr);
    pop(arr);
    pop(arr);
    display(arr);
    return 0;
}