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

void solve()
{
    vector<int> d(n + 1, 0);
    vector<int> p(n + 1, -1);
    int no_of_iter = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        no_of_iter++;
        bool any = false;

        for (edge e : edges)
        {
            if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost)
            {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                any = true;
                p[e.b] = e.a;
                x = e.b;
            }
        }
        if (any == false)
        {
            break;
        }
    }

    if (x == -1)
        cout << "No negative cycle from " << s;
    else
    {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur = y;; cur = p[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}
int main()
{
    cout << "Enter the no of nodes\nno of edges\nthe source vertex\n";
    cin >> n >> m;
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

    solve();
}

/*
inp:
5
5
1 3 -2
2 1 4
3 2 -3
2 5 2
3 4 2
*/