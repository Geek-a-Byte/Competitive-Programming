#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
vector<int> adj[100000];
bool visited[100000];
int dist[100000];

void printGraph()
{
    for (int i = 1; i <= nodes; i++)
    {
        cout << "element at index " << i << " :";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void printDistance()
{
    for (int i = 1; i <= nodes; i++)
    {
        cout << "Dist of node " << i << " from source is: " << dist[i] << endl;
    }
    cout << endl;
}
void initDIST()
{
    for (int i = 1; i <= nodes; i++)
    {
        dist[i] = 0;
    }
}
void initVisited()
{
    for (int i = 1; i <= nodes; i++)
    {
        visited[i] = false;
    }
}
void bfs(int start)
{
    cout << "BFS TRAVERSAL: " << endl;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int king = q.front();
        cout << king << " ";
        q.pop();
        //je king tar adj gula / child gula pore
        for (int k : adj[king])
        {
            if (!visited[k])
            {
                dist[k] = dist[king] + 1;
                q.push(k);
                visited[k] = true;
            }
        }
    }
    cout << endl;
}
int main()
{
    initDIST();
    initVisited();
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    printGraph();
    printDistance();
}