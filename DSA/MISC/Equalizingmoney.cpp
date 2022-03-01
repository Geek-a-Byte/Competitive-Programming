#include <bits/stdc++.h>
#define PII pair<int, int>
#define MX 13

using namespace std;

vector<PII> g[1000000];
//map<int, vector<int>> mp;

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            cout << "(" << j.first << "," << j.second << ")"
                 << " ";
        }
        cout << endl;
    }
}