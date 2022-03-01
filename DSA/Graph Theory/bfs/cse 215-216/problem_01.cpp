#include <bits/stdc++.h>
using namespace std;
int n, e;

void bfs(vector<int> adj[])
{
    int visited[n] = {0};
    int total_disconnected_components = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                int parent = q.front();
                q.pop();
                for (int k = 0; k < adj[parent].size(); k++)
                {
                    if (!visited[adj[parent][k]])
                    {
                        visited[adj[parent][k]] = 1;
                        q.push(adj[parent][k]);
                    }
                }
            }
            total_disconnected_components++;
        }
    }
    cout << total_disconnected_components << endl;
}

int main()
{
    //number of nodes->n and number of edges->e
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(adj);
}
