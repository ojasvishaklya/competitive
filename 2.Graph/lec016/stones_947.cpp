#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> parent;
    vector<int> size;
    int ans = 0;

    int find(int n)
    {
        if (n == parent[n])
            return n;
        else
            return parent[n] = find(parent[n]);
    }
    void merge(int i, int j)
    {
        int p1 = find(i);
        int p2 = find(j);
        if (p1 == p2)
            return;
        if (p1 != p2)
        {
            if (size[p1] > size[p2])
            {
                parent[p2] = p1;
                size[p1]++;
            }
            if (size[p1] <= size[p2])
            {
                parent[p1] = p2;
                size[p2]++;
            }
        }
        ans++;
        return;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();

        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(0);
        }

        for (int i = 0; i < stones.size(); i++)
            for (int j = i + 1; j < stones.size(); j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    merge(i, j);
                }

        for (int i = 0; i < n; i++)
        {
            cout << i << "->parent->" << parent[i] << "->size->" << size[i];
            cout << endl;
        }

        return ans;
    }
};