#include <bits/stdc++.h>

using namespace std;
int n, e;
int visited[100];
vector<int> adj[100];
void initVISITED()
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

void dfs(int s)
{
    visited[s] = 1;
    cout << s << " ";
    for (auto i : adj[s])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int c = 0;
        cin >> n >> e;
        initVISITED();
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        printVect();
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                c++;
            }
        }
        cout << "total clusters are: " << c << "\n";
        cout << "\n\n";
    }
    return 0;
}