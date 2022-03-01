#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int visited[1005] = {0};
int dest[1005];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    *(visited + start) = true;

    while (!q.empty())
    {
        int king = q.front();
        // cout << king << endl;
        q.pop();

        for (auto i = adj[king].begin(); i != adj[king].end(); i++)
        {
            // cout << *i;
            if (!visited[*i])
            {
                dest[*i]++;
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        visited[i] = 0;
    }
    // cout << endl;
}

int main()
{

    int T;
    int k, n, m;
    cin >> T;
    for (int z = 1; z <= T; z++)
    {

        int src_array[100];
        cin >> k >> n >> m;
        // cout << k << n << m << endl;
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            dest[i] = 0;
            visited[i] = 0;
        }
        int i = 0;

        while (i < k)
        {
            cin >> src_array[i];
            dest[src_array[i]]++;
            i++;
        }
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int l = 0;
        while (l < k)
        {
            bfs(src_array[l]);
            l++;
        }
        int ans = 0;
        int j = 1;
        while (j <= n)
        {
            // cout << dest[j] << " ";
            if (dest[j] == k)
            {
                ans++;
            }
            j++;
        }
        // cout << endl;
        //Case 1: 2
        cout << "Case " << z << ": " << ans << endl;
    }
}
