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
void display(vector<vector<edge>> &gp)
{
    cout << endl
         << "***************************************************" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i << " -> ";
        for (edge e : gp[i])
        {
            cout << "(" << e.v << "," << e.w << ") ";
        }
        cout << endl;
    }

    cout << endl
         << "***************************************************" << endl;
}

class dpair
{
public:
    int src;
    int par;
    int w;
    int wsf;

    dpair(int src, int par, int w, int wsf)
    {
        this->src = src;
        this->par = par;
        this->w = w;
        this->wsf = wsf;
    }
};

struct comp
{
public:
    bool operator()(dpair &p1, dpair &p2)
    {
        return p1.wsf > p2.wsf;
    }
};
struct comp2
{
public:
    bool operator()(dpair &p1, dpair &p2)
    {
        return p1.w > p2.w;
    }
};
int main()
{
    int src = 3;
    priority_queue<dpair, vector<dpair>, comp> q;
    vector<bool> vis(N, false);
    vector<vector<edge>> graph(N, vector<edge>());
    vector<vector<edge>> dgraph(N, vector<edge>());
    //making graph
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 4, 6, 1);
    cout << "ORIGINAL GRAPH";
    display(graph);

    q.push(dpair(src, -1, 0, 0));

    while (q.size())
    {
        int size = q.size();
        while (size-- > 0)
        {
            dpair vtx = q.top();
            q.pop();

            if (vis[vtx.src] == true)
                continue;
            vis[vtx.src] = true;
            if (vtx.par != -1)
                addEdge(dgraph, vtx.src, vtx.par, vtx.w);

            for (edge e : graph[vtx.src])
            {
                if (!vis[e.v])
                    q.push(dpair(e.v, vtx.src, e.w, vtx.wsf + e.w));
            }
        }
    }
    cout << "GRAPH AFTER DIJKSTRA";

    display(dgraph);
}