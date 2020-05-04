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

class answer{

    public:
    int low = 1e7;
    int high = 0 ;
    int floor=0;
    int ciel=1e7;
};



int DFS(int s, int d, string ans, int w, int t,answer &pair)

{
    if (s == d)
    {pair.low=min(pair.low,w);
    pair.high=max(pair.high,w);

    if(w<t)
    pair.floor=max(pair.floor,w);

    if(w>t)
    pair.ciel=min(pair.ciel,w);

        cout <<"Took path : "<< ans << d <<endl<<" at a weight of "<<w<< endl<<endl;
        return 1;
    }

    int count = 0;
    vis[s] = true;

    for (Edge e : graph[s])
    {
        if (!vis[e.v])
            count += DFS(e.v, d, ans + to_string(s) + " ", w+e.w,t,pair);
    }
    vis[s] = false;

    return count;
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
    display(graph);
    int source = 0;
    int destination = 6;
    int target =35;
    answer pair;

    cout << DFS(source, destination, "", 0,target,pair)<<endl;
    cout<<"pair.low : "<<pair.low<<endl<<"pair.high : "<<pair.high<<endl<<"pair.floor : "<<pair.floor<<endl<<"pair.ciel : "<<pair.ciel<<endl;
    return 0;
}