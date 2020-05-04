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

void removeEdge(vector<vector<Edge>> &gp, int r, int c)
{
    int i = 0;
    for (Edge e : graph[r])
    {
        if (e.v == c)
        {
            graph[r].erase(graph[r].begin() + i);
        }
        i++;
    }

         i = 0;
    for (Edge e : graph[c])
    {
        if (e.v == r)
        {
            graph[c].erase(graph[c].begin() + i);
        }
        i++;
    }
}

void removeVertex(vector<vector<Edge>> &gp, int r)
{

    for (int i = 0; i < graph.size(); i++)
    {
        int k = 0;
        for (Edge e : graph[i])
        {
            if (e.v == r)
            {
                graph[i].erase(graph[i].begin() + k);
            }
            k++;
        }
    }
    graph[r].clear();
}

int main()
{
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 10);
    addEdge(graph, 6, 5, 10);
    addEdge(graph, 3, 7, 10);
    addEdge(graph, 9, 7, 10);
    addEdge(graph, 1, 8, 10);
    addEdge(graph, 4, 2, 10);
    addEdge(graph, 4, 7, 10);
    display(graph);
    removeEdge(graph, 6, 5);
    display(graph);
    removeVertex(graph, 7);
    display(graph);
    return 0;
}