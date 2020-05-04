#include <iostream>
#include <vector>
#include <queue>

 vector<int>parent;
      int par(int n)
    {
        if(n==parent[n])
            return n;
        else
            return parent[n]=par(parent[n]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        
        for(int i=0;i<=edges.size();i++)
        {
            parent.push_back(i);
        }
        for(auto ar: edges)
        {
            int a=(ar[0]);
            int b=(ar[1]);
        int rootA = par(a);
        int rootB = par(b);
        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
            else return ar;

        }
        
       
        return {};
    }