#include <bits/stdc++.h>
using namespace std;

int nodes;
map<string, int> map1;
int vis[50] = {0};
vector<int> adj[50];
vector<int> path[50];
vector<string> str;

void printPath(int end_node)
{
    if (end_node == 0)
    {
        cout << "File not found" << endl;
        cout << "-1" << endl;
    }
    else
    {
        cout << "Absolute path for ";
        cout << str[end_node - 1] << " : ";
        for (int k : path[end_node])
        {
            if (str[k - 1] == "c")
                cout << str[k - 1] << ":\\";
            else
            {
                cout << str[k - 1] << "\\";
            }
        }
        cout << str[end_node - 1] << endl;
        cout << "Number of mouse clicks required for opening " << str[end_node - 1] << ": " << path[end_node].size() * 2 + 2 << "\n\n";
    }
}

void bfs(int start_node)
{
    //store {child,parent} as a pair in the queue
    queue<pair<int, int>> qu;
    qu.push({start_node, -1});
    vis[start_node] = 1;
    while (!qu.empty())
    {
        pair<int, int> p = qu.front();
        qu.pop();
        //vis[p.first] = 1;
        for (int child : adj[p.first])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                qu.push({child, p.first});
                path[child] = path[p.first];
                path[child].push_back(p.first);
            }
        }
    }
}

int main()
{
    cin >> nodes;
    int count = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        string x, y;
        cin >> x >> y;
        if (map1[x] == 0)
        {
            count++;
            str.push_back(x);
            map1[x] = count;
        }
        if (map1[y] == 0)
        {
            count++;
            str.push_back(y);
            map1[y] = count;
        }
        adj[map1[x]].push_back(map1[y]);
        adj[map1[y]].push_back(map1[x]);
    }
    int query;
    cin >> query;
    for (int j = 1; j <= query; j++)
    {
        string Q;
        cin >> Q;
        bfs(map1["c"]);
        printPath(map1[Q]);
    }
}
/*
7
codes bfs.cpp
c cse19
c a.jpg
cse19 dsalgo
c codes
dsalgo graphtheory 
3
bfs.cpp
cse19
koushik.jpg
*/