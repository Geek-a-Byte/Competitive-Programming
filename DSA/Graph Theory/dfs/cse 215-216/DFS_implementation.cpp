#include <bits/stdc++.h>
using namespace std;

int visited[100];
int discover[100];
int finish[100];
vector<int> adj[100];
int t;

void dfs(int node)
{
    visited[node] = 1; //discovered
    t = t + 1;
    discover[node] = t;
    for (auto v : adj[node])
    {
        if (visited[v] == 0)
        {
            dfs(v);
        }
    }
    t = t + 1;
    finish[node] = t;
    visited[node] = -1; //explored
}
int main()
{
    freopen("inp", "r", stdin);
    int n; //number of nodes
    int caseNo = 1;
    while (cin >> n)
    {
        int edges, a, b;
        memset(visited, 0, sizeof(visited));
        memset(discover, 0, sizeof(discover));
        memset(finish, 0, sizeof(finish));
        t = 0;

        for (int i = 0; i <= 100; i++)
        {
            adj[i].clear();
        }

        cin >> edges;
        for (int i = 0; i < edges; i++)
        {
            cin >> a >> b;
            //undirected
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
        printf("#test case : %d\n", caseNo++);
        for (int i = 1; i <= n; i++)
        {
            printf("node %d = discover time = %d , Finish Time =%d\n", i, discover[i], finish[i]);
        }
    }
}