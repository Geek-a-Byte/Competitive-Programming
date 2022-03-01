// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

// variables to be used
// in both functions
vector<int> adj[N];

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[],
               int par[], int &cyclenumber)
{

    // already (completely) visited vertex.
    if (color[u] == 2)
    {
        return;
    }

    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1)
    {
        cyclenumber++;
        return;
    }

    par[u] = p;

    // partially visited.
    color[u] = 1;

    // simple dfs on graph
    for (int v : adj[u])
    {

        // if it has not been visited previously
        if (v == par[u])
        {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }

    // completely visited.
    color[u] = 2;
}

// Driver Code
int main()
{

    freopen("inp", "r", stdin);
    int caseNo = 1;
    int n;
    while (cin >> n)
    {
        int i, edges, a, b;

        for (i = 0; i <= n; i++)
            adj[i].clear();

        scanf("%d", &edges);

        for (i = 0; i < edges; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("#Test Case: %d\n", caseNo++);

        // arrays required to color the
        // graph, store the parent of node
        int color[n] = {0};
        int par[n] = {0};

        // store the numbers of cycle
        int cyclenumber = 0;

        // call DFS to mark the cycles
        dfs_cycle(1, 0, color, par, cyclenumber);

        cout << cyclenumber << endl;
    }
}

// in an undirected graph
