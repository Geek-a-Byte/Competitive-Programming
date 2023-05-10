#include <bits/stdc++.h>
using namespace std;

int adj[50][50];
int p[50][50]; //parent matrix
const int INF = 0x3f3f3f3f;
int n; //num of nodes
int m; //num of edges
void printPath(int i, int j)
{

    cout << i << " ";
    while (i != j)
    {
        /* code */
        i = p[i][j];
        cout << i << " ";
    }
}

int main()
{
    cout << "enter the number of nodes & edges\n";
    cin >> n >> m;
    memset(adj, INF, sizeof(adj));
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //p[i][j] = i; //then p[i][j] = p[k][j]; in FW loop
            p[i][j] = j; //then p[i][j] = p[i][k]; in FW loop
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                }
                else if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    //condition is needed if you want to update the parent matrix
                    //else the line d[i][j] = min(d[i][j], d[i][k] + d[k][j]); can be written without any condition
                    p[i][j] = p[i][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    int s, d;
    cout << "enter the source and dest\n";
    cin >> s >> d;
    printPath(s, d);
}

/*
inp:
4
6
3 0 20
3 2 8 
2 1 5
1 2 2
1 0 2
0 1 3
0 2
*/