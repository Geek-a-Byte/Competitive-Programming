#include <bits/stdc++.h>
using namespace std;
int flag;
void dfs(vector<int> &color, vector<int> adj[], int curr, int curr_col)
{
    if (color[curr] == 0)
    {
        color[curr] = curr_col;
    }

    else if (color[curr] != curr_col)
    {
        flag++;
        return;
    }
    else
        return;
    for (int u : adj[curr])
    {
        if (curr_col == 1)
        {
            dfs(color, adj, u, 2);
        }
        else
        {
            dfs(color, adj, u, 1);
        }
    }
}

int main()
{

    int nodes;

    freopen("input", "r", stdin);
    while (scanf("%d", &nodes) != EOF)
    {
        flag = 0;
        int edges;
        cin >> edges;
        vector<int> adj[nodes + 1];
        vector<int> color(nodes + 1, 0);
        for (int i = 0; i <= nodes; i++)
            adj[i].clear();
        for (int i = 0; i < edges; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= nodes; i++)
        {
            cout << i << " --> ";
            for (int u : adj[i])
            {
                cout << u << " ,";
            }
            cout << endl;
        }

        for (int i = 1; i <= nodes; i++)
        {
            if (color[i] == 0)
            {
                dfs(color, adj, i, 1);
            }
        }

        for (int i = 1; i <= nodes; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
        if (flag)
        {
            cout << "the graph is not bipartite or bicolourable";
        }
        else
        {
            cout << "the graph is bipartite or bicolourable";
        }
        cout << endl
             << endl;
    }
}