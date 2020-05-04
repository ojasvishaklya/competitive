class Solution
{
public:
    vector<int> parent;

    int par(int n)
    {
        if (n == parent[n])
            return n;
        return parent[n] = par(parent[n]);
    }

    int findCircleNum(vector<vector<int>> &M)
    {

        int n = M.size();
        if (n == 0)
            return -1;

        int count = n;
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i != j && M[i][j] == 1)
                {
                    int p1 = par(i);
                    int p2 = par(j);

                    if (p1 != p2)
                    {
                        parent[p1] = p2;
                        count--;
                    }
                }
            }

        return count;
    }
};