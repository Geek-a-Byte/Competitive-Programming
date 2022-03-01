#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        int node, edge;
        cin >> node >> edge;
        vector<int> v[node];
        map<int, int> visited;
        map<int, int> dis;
        for (int j = 1; j <= edge; j++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            for (int k = 0; k < v[parent].size(); k++)
            {
                if (!visited[v[parent][k]])
                {
                    visited[v[parent][k]] = 1;
                    dis[v[parent][k]] = dis[parent] + 1;
                    q.push(v[parent][k]);
                }
            }
        }

        cout << dis[node - 1] << endl;
    }
}

//OR

// #include <bits/stdc++.h>
// using namespace std;

// map<int, int> visited;
// map<int, int> dis;

// int main()
// {
//     int test;
//     cin >> test;
//     for (int i = 1; i <= test; i++)
//     {
//         int node, edge;
//         cin >> node >> edge;
//         vector<int> v[node];

//         for (int j = 1; j <= edge; j++)
//         {
//             int x, y;
//             cin >> x >> y;
//             x--;
//             y--;
//             v[x].push_back(y);
//             v[y].push_back(x);
//         }

//         queue<int> q;
//         q.push(0);
//         visited[0] = 1;

//         while (!q.empty())
//         {
//             int parent = q.front();
//             q.pop();
//             for (int k = 0; k < v[parent].size(); k++)
//             {
//                 if (!visited[v[parent][k]])
//                 {
//                     visited[v[parent][k]] = 1;
//                     dis[v[parent][k]] = dis[parent] + 1;
//                     q.push(v[parent][k]);
//                 }
//             }
//         }

//         cout << dis[node - 1] << endl;
//         visited.clear();
//         dis.clear();
//     }
// }

//or

// #include <bits/stdc++.h>
// using namespace std;
// int n, e;
// vector<vector<int>> v;
// void bfs(int start, int mark[], int dis[])
// {
//     queue<int> q;
//     q.push(start);
//     mark[start] = 1;
//     while (q.size() != 0)
//     {
//         int parent = q.front();
//         //cout<<parent<<" ";
//         q.pop();
//         for (int i = 0; i < v[parent].size(); i++)
//         {
//             if (mark[v[parent][i]] == 0)
//             {
//                 int child = v[parent][i];
//                 q.push(child);
//                 dis[child] = dis[parent] + 1;
//                 mark[child] = 1;
//             }
//         }
//     }
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> e;
//         v.assign(n + 1, vector<int>());
//         int mark[n + 1]={0};
//         int dis[n + 1]={0};

//         int x, y;
//         for (int i = 0; i < e; i++)
//         {
//             cin >> x >> y;
//             v[x].push_back(y);
//             v[y].push_back(x);
//         }
//         bfs(1, mark, dis);
//         cout << dis[n] << endl;
//     }
// }