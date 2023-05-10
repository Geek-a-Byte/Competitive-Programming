#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int mem[MAXN][2];
int par[MAXN];

vector<int> edges[MAXN];

int f(int u, int isGuard)
{
    if (mem[u][isGuard] != -1)
    {
        return mem[u][isGuard];
    }

    int answer = isGuard;

    for (auto v : edges[u])
    {
        if (v == par[u])
            continue;
        par[v] = u;
        if (isGuard == 0)
        {
            answer += f(v, 1);
        }
        else
        {
            answer += min(f(v, 1), f(v, 0));
        }
    }

    return mem[u][isGuard] = answer;
}
int main()
{
    memset(mem, -1, sizeof(mem));
    memset(par, -1, sizeof(par));
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans = 0;
    ans = min(f(1, true), f(1, false));
    cout << ans << endl;
    return 0;
}
