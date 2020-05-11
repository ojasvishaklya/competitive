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

int main()
{
    int n, r;
    long long k;
    cin >> n >> r >> k;
    vector<vector<int>> roads(r, vector<int>(3, 0));
    for (int i = 0; i <= n; i++)
        parent.push_back(i);
    for (int i = 0; i < r; i++)
    {
        cin >> roads[i][0];
        cin >> roads[i][1];
        cin >> roads[i][2];
    }

    sort(roads.begin(), roads.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
    long long cost = 0;
    vector<vector<int>> res;
    int count = 0;
    for (vector<int> &p : roads)
    {

        int p1 = find(p[0]);
        int p2 = find(p[1]);

        if (p1 != p2)
        {
            parent[p1] = p2;
            res.push_back(p);
            cost += p[2];
        }
    }
    int cc = 0;

    for (int i = 0; i <= n; i++)
        if (parent[i] == i && ++cc > 2)
        {

            cout << "-1";
            return 0;
        }

    int c = 0;
    for (int i = res.size() - 1; i >= 0; i--)
    {

        if (cost > k)
        {
            cost = cost - res[i][2] + 1;
            res[i][2] = 1;
            c++;
        }
        else
            break;
    }

    if (cost > k)
    {
        cout << "-1";
        return 0;
    }
    cout << c;
    return 0;
}