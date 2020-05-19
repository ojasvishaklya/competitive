#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class edge
{

public:
    int v;
    int w;

    edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;

void addEdge(vector<vector<edge>> &gp, int u, int v, int w)
{
    edge e = edge(v, w);
    gp[u].push_back(e);
    e = edge(u, w);
    gp[v].push_back(e);
}


vector<bool> vis(N, false);
vector<int> dis(N, 0);
vector<int> low(N, 0);
vector<int> AP(N, 0);
vector<vector<edge>> graph(N, vector<edge>());
int time = 0;
void DFS(int src, int par)

{
    dis[src] = low[src] = time++;
    vis[src] = true;

    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            DFS(e.v, src);

            if (dis[src] <= low[e.v])
                AP[src]++;
            low[src] = min(low[src], low[e.v]);
        }
        else if (e.v != par)
            low[src] = min(dis[e.v], low[src]);
    }
}

int main()
{
    int src = 0;
    vector<bool> vis(N, false);
    //making graph
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 4, 6, 1);
DFS(0,0);

    for (int i = 0; i < AP.size(); i++)
    {
        if (AP[i])
            cout << i << " is an articulation point with dependent components : " << AP[i]<<endl;
    }
    return 0;
}