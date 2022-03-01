#include <bits/stdc++.h>
using namespace std;
map<string, int> map1;
vector<int> adj[50];
void bfs(vector<int> adj[], int n)
{
    int visited[n] = {0};
    int total_disconnected_components = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                int p = q.front();
                q.pop();
                for (auto k : adj[p])
                {
                    if (!visited[k])
                    {
                        visited[k] = 1;
                        q.push(k);
                    }
                }
            }
            total_disconnected_components++;
        }
    }
    cout << total_disconnected_components << endl;
}

int main()
{
    int n;
    cin >> n;
    int count = -1;
    for (int i = 1; i <= n; i++)
    {
        string x, y;
        cin >> x >> y;

        if (map1[x] == 0)
        {
            count++;
            map1[x] = count;
        }
        if (map1[y] == 0)
        {
            count++;
            map1[y] = count;
        }
        adj[map1[x]].push_back(map1[y]);
        adj[map1[y]].push_back(map1[x]);
    }
    bfs(adj, count);
    //cout << "end";
}