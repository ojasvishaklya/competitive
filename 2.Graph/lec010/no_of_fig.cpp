#include <iostream>
#include <vector>
using namespace std;

class Edge
{

public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int n = 16;
vector<vector<Edge>> graph(n, vector<Edge>());
vector<bool> vis(n, false);

void addEdge(vector<vector<Edge>> &gp, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

void display(vector<vector<Edge>> &gp)
{

    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << " -> ";
        for (Edge e : gp[i])
        {
            cout << " (" << e.v << "," << e.w << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int src)
{
    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
            dfs(e.v);
    }
    return;
}

int main()
{
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 10);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 4, 6, 10);
    addEdge(graph, 5, 6, 10);
    addEdge(graph, 7, 8, 10);
    addEdge(graph, 9, 8, 10);
    addEdge(graph, 10, 8, 10);
    addEdge(graph, 11, 8, 10);
    addEdge(graph, 10, 11, 10);
    addEdge(graph, 13, 15, 10);
    addEdge(graph, 12, 15, 10);
    addEdge(graph, 11, 15, 10);
    addEdge(graph, 10, 15, 10);

    display(graph);
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
            count++;
            dfs(i);
        }
    }
    cout << count;

    return 0;
}