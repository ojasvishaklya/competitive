#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
int numBusesToDestination(vector<vector<int>> &routes, int S, int T)
{
    int n = routes.size();
    if (n == 0)
        return -1;
    int m = routes[0].size();
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < routes.size(); i++)
    {
        for (auto e : routes[i])
        {
            map[e].push_back(i);
        }
    }

    unordered_set<int> stands;
    vector<bool> buses(routes.size(), false);

    queue<int> q;
    q.push(S);
    int level = 0;
    stands.insert(S);

    while (q.size())
    {
        int size = q.size();
        while (size-- > 0)
        {
            int stand = q.front();
            q.pop();
            if (stand == T)
                return level;
            for (auto bus : map[stand])
            {
                if (buses[bus] == true)
                    continue;
                else
                {
                    for (auto e : routes[bus])
                    {
                        if (stands.count(e) == 0)
                        {
                            q.push(e);
                            stands.insert(e);
                        }
                    }
                }
                buses[bus] = true;
            }
        }
        level++;
    }


        return -1;
}