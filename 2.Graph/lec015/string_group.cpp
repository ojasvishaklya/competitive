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

    bool isSimilar(string &a, string &b)
    {
        int c = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && ++c > 2)
                return false;
        return true;
    }

    int numSimilarGroups(vector<string> &A)
    {
        int n = A.size();
        if (n == 0)
            return -1;

        int count = n;
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
            {
                if (isSimilar(A[i],A[j]))
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