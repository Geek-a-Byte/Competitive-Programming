#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> adj[100];
int visited[100];
int dist[100];
void initDist()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0;
    }
}

void initVisited()
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
}

void printVect()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
void printDis()
{
    cout << "distance from root of\n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> " << dist[i];
        cout << "\n";
    }
}

void bfs(int start)
{
    cout << "BFS sequence: ";
    dist[start] = 0;
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int king = q.front();
        q.pop();
        cout << king << " ";
        for (auto i : adj[king])
        {

            int child = i;
            if (!visited[child])
            {

                q.push(child);
                visited[child] = 1;
                dist[child] = dist[king] + 1;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        initDist();
        initVisited();
        cin >> n >> e;

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> ";
            for (auto j : adj[i])
            {
                cout << j << " ";
            }
            cout << "\n";
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                bfs(i);
            }
        }

        cout << "\n";
        printDis();
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
    //printVect(adj);
}