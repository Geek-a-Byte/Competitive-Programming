#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
vector<int> adj[100000];
bool visited[100000];
int dist[100000];

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
    //cout << "BFS TRAVERSAL: " << endl;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int king = q.front();
        //cout << king << " ";
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
    //cout << endl;
}
int max()
{
    int max = dist[0];
    int max_index = 0;
    for (int i = 0; i < sizeof(dist) / sizeof(int); i++)
    {
        if (max < dist[i])
        {
            max = dist[i];
            max_index = i;
        }
    }
    return max_index;
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
    int max_index = max();
    initDIST();
    initVisited();
    bfs(max_index);
    int max_dist = dist[max()];
    cout << "DIST: " << max_dist << endl;
    //printGraph();
    //printDistance();
}