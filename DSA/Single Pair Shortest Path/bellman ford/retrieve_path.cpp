#include <bits/stdc++.h>
using namespace std;

typedef struct edge
{
    int a, b, cost;
} edge;

vector<edge> edges;
int n; //num of nodes
int m; //num of edges
int s; //starting vertex;

const int INF = 1000000000; //macros (#define) can be redefined but const can't be

void solve(int t)
{
    vector<int> d(n + 1, INF);
    vector<int> p(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    d[s] = 0;
    int no_of_iter = 0;
    for (;;)
    {
        no_of_iter++;
        bool any = false;

        for (edge e : edges)
        {
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost)
            {
                d[e.b] = d[e.a] + e.cost;
                any = true;
                p[e.b] = e.a;
            }
        }
        if (any == false)
        {
            break;
        }
    }
    cout << "\nno of iterations: " << no_of_iter << endl; //2 bcoz of optimization
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    if (d[t] == INF)
        cout << "No path from " << s << " to " << t << ".";
    else
    {
        vector<int> path;
        for (int cur = t; cur != -1; cur = p[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << "Path from " << s << " to " << t << ": ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}
int main()
{
    cout << "Enter the no of nodes\nno of edges\nthe source vertex\n";
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge e;
        e.a = a;
        e.b = b;
        e.cost = c;
        edges.push_back(e);
    }
    cout << "enter the node to which we need to explore\n";
    int t;
    cin >> t;
    solve(t);
}

/*
inp:
6
6
1
1 4 4
1 3 2
2 3 10
3 4 1
4 5 6
4 6 5
*/