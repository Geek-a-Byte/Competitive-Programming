//https://www.youtube.com/watch?v=sxZeqEgJsYs
#include <bits/stdc++.h>
using namespace std;
int flag;

void dfs(vector<int> &color, vector<int> adj[], int curr, int curr_col) //curr=
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
    {
        return;
    }
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
    while (cin >> nodes)
    {
        flag = 0;
        int edges;
        cin >> edges;
        vector<int> adj[nodes + 1];      //size
        vector<int> color(nodes + 1, 0); //first -> size, second -> initialing value
        for (int i = 0; i < edges; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= nodes; i++)
        {
            //color eikhane mark hishebe kaj korbe
            if (color[i] == 0)
            {
                dfs(color, adj, i, 1); // color vector, adj vector, curr node er index, curr_node er color
            }
        }
        //color duita 1,0
        //jekono duita adjacent node er color jodi same hoy taile bicoloring hobe na
        for (int i = 1; i <= nodes; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
        if (flag > 0)
        {
            cout << "the graph is not bipartite/bicolourable" << endl;
        }
        else
        {
            cout << "the graph is bipartite/bipartite" << endl;
        }
    }
}