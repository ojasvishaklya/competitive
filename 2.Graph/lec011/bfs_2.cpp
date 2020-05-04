#include <iostream>
#include <vector>
#include <queue>
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

int n = 10;
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

void bfs(int src, int dest)
{
    queue<int> q;
    q.push(src);
    vis[src] == true;
    int level = 0;

    while (q.size() != 0)
    {
        int size = q.size();
        while (size-- > 0)
        {
            int vtx = q.front();
            q.pop();
            if (vtx == dest)
            {
                cout << "found at: " << level;
            }

            for (Edge e : graph[vtx])
            {
                if (vis[e.v] == false)
                {
                    vis[e.v] = true;
                    q.push(e.v);
                }
            }
        }

        level++;
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
    addEdge(graph, 2, 5, 10);

    display(graph);
    int source = 0;
    int dest = 6;

    bfs(source, dest);
    return 0;
}