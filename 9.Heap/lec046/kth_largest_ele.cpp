// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution
{
public:
    int findKthLargest(vector<int> &arr, int k)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < arr.size(); i++)
        {
            if (pq.size() == k)
            {
                pq.push(arr[i]);
                pq.pop();
                continue;
            }
            pq.push(arr[i]);
        }

        return pq.top();
    }
};