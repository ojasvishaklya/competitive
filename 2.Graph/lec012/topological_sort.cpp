#include <iostream>
#include <vector>
using namespace std;

int n = 10;
vector<vector<int>> graph(n, vector<int>());
vector<bool> vis(n, false);

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

void display()
{

    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (int e : graph[i])
        {
            cout << " (" << e << ")";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int src, vector<int> &ans)
{
    vis[src] = true;

    for (int e : graph[src])
    {
        if (vis[e] == false)
        {
            dfs(e, ans);
        }
    }
    ans.push_back(src);

    return;
}

int main()
{
    addEdge(graph, 8, 9);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 4, 2);
    addEdge(graph, 4, 3);
    addEdge(graph, 3, 2);
    addEdge(graph, 5, 2);
    addEdge(graph, 3, 5);
    addEdge(graph, 8, 2);
    addEdge(graph, 8, 6);
    addEdge(graph, 7, 6);

    display();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            dfs(i, ans);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << " (" << ans[i] << ")" << endl;
    return 0;
}