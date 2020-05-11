#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parent;

int find(int n)
{
    if (n == parent[n])
        return n;
    return parent[n] = find(parent[n]);
}

int water_distribution_cost()
{
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]}); //convert every well into a pipe itself
    }
    for (int i = 0; i <= wells.size(); i++)
        parent.push_back(i);

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2]; //sorts the array in ascending order based on the 2nd index
    });
    int cost = 0;
    for (vector<int> &p : pipes)
    {

        int p1 = find(p[0]);
        int p2 = find(p[1]);

        if (p1 != p2)
        {
            parent[p1] = p2;
            cost++; //adds the cost for evey construction
        }
    }
    return cost;
}


