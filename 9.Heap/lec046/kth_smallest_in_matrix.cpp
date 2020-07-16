class Solution
{
public:
    int kthSmallest(vector<vector<int>> &arr, int k)
    {

        int n = arr.size();
        if (!n)
            return 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int j = 0; j < n; j++)
        {
            pq.push({arr[0][j], 0, j});
        }

        while (k-- > 1)
        {
            vector<int> ele = pq.top();
            int i = ele[1];
            int j = ele[2];
            pq.pop();
            if(i+1<n)
            pq.push({arr[i + 1][j], i + 1, j});
        }

        return pq.top()[0];
    }
};