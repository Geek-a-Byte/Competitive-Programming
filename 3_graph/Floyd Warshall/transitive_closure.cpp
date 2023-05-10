#include <bits/stdc++.h>
using namespace std;

int adj[50][50];
const int INF = 0x3f3f3f3f;
int n; //num of nodes
int m; //num of edges

int main()
{
    cout << "enter the number of nodes & edges\n";
    cin >> n >> m;
    memset(adj, 0, sizeof(adj));
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //check whether there is a direct edge from i to j
                //if after printing adj matrix
                //adj[i][j]=1 then there is a direct edge
                //otherwise not
                if (i == j)
                {
                    adj[i][j] = 0;
                }
                else
                {
                    adj[i][j] |= adj[i][k] & adj[k][j];
                }
            }
        }
    }
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

/*
inp:
4
6
3 0 
3 2  
2 1 
1 2 
1 0 
0 1 
0 2
*/