#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> adj[100];
int visited[100];
int dist[100];
map<char, int> mp;
vector<char> c;
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
        cout << c[i - 1] << " -> " << dist[i];
        cout << "\n";
    }
}
int max_i()
{
    int max = dist[0];
    int max_index;
    for (int i = 1; i <= n; i++)
    {
        if (max < dist[i])
        {
            max = dist[i];
            max_index = i;
        }
    }
    return max_index;
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
        cout << c[king - 1] << " ";
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
        mp.clear();
        c.clear();
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        initDist();
        initVisited();
        cin >> n >> e;
        int count = 0;
        for (int i = 0; i < e; i++)
        {
            char u, v;
            cin >> u >> v;
            if (mp[u] == 0)
            {
                count++;
                mp[u] = count;
                c.push_back(u);
            }
            if (mp[v] == 0)
            {
                count++;
                mp[v] = count;
                c.push_back(v);
            }
            // cout << mp[u] << " ";
            // cout << mp[v] << " \n";

            adj[mp[u]].push_back(mp[v]);
            adj[mp[v]].push_back(mp[u]);
        }
        // for (int i = 0; i < c.size(); i++)
        // {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << c[i - 1] << " -> ";
            for (auto j : adj[i])
            {
                cout << c[j - 1] << " ";
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
        int max = max_i();
        initDist();
        initVisited();
        cout << "\n";
        bfs(max);

        int max_dist = dist[max_i()];
        cout << "\nmaximum distance is " << max_dist << "\n";

        cout << "\n";
        //printDis();
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
    //printVect(adj);
}