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



void hamiltonian(int src, int osrc, string ans, int c)
{
    if (c == 6)
    {
        cout << "Took path : " << ans << src << endl;
        return ;
    }
    int count = 0;
    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
           hamiltonian(e.v, osrc, ans + to_string(src) + " ", c + 1);
    }
        vis[src] = false;

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
    int source = 2;


hamiltonian(source, source, "", 0) ;

    return 0;
}