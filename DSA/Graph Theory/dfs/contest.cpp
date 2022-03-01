#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2 * 10 ^ 5];
int visited[2 * 10 ^ 5] = {0};
int marked[2 * 10 ^ 5] = {0};

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        marked[i] = 0;
    }
}
int c;
void dfs(int r, int a[], int n)
{
    visited[r] = 1;
    marked[a[r - 1]]++;
    for (auto u : adj[r])
    {

        if (visited[u] == 0)
        {
            dfs(u, a, n);
                }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c1 = 0;
    for (int i = 1; i <= n; i++)
    {

        dfs(i, a, n);
        cout << c << " ";
        init(n);
    }
    cout << endl;
    cout << n - c;
    cout << endl;
}
