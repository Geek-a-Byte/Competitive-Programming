//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int t, visited[100], discover[100], finish[100];
vector<int> adj[100];

void dfs(int node)
{
    visited[node] = 1;
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
    visited[node] = -1;
}

int main()
{
    freopen("inp", "r", stdin);
    int n, caseNo = 1;
    while (scanf("%d", &n) != EOF)
    {
        int edges, a, b;
        memset(visited, 0, sizeof(visited));
        memset(discover, 0, sizeof(discover));
        memset(finish, 0, sizeof(finish));
        t = 0;
        for (int i = 0; i <= 100; i++)
            adj[i].clear();

        cin >> edges;
        for (int i = 0; i < edges; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
                dfs(i);
        }
        printf("#Test Case: %d\n", caseNo++);
        for (int i = 1; i <= n; i++)
        {
            printf("node %d = discover time = %d, Finish Time = %d\n", i, discover[i], finish[i]);
        }
    }
}