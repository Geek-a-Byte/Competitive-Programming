// Adjascency List representation in C++

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int V, e;
// Add edge
void addEdge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void printGraph(vector<int> adj[])
{
    cout << endl;
    for (int i = 0; i < V; i++)
    {

        cout << "Elements at index "
             << i << ": ";

        for (auto it : adj[i])
        {
            cout << it << ' ';
        }
        cout << endl;
    }
}
void printDis(int dis[])
{
    cout << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "distance"
             << " of  " << i << " is " << dis[i] << endl;
    }
}

void initVisited(bool visited[])
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
}
void initDis(int dis[])
{
    for (int i = 0; i < V; i++)
    {
        dis[i] = 0;
    }
}

void bfs(vector<int> adj[], int start, bool visited[], int dis[])
{
    //initMark();
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int king = q.front();
        cout << king << " ";
        q.pop();

        for (auto i : adj[king])
        {
            if (!visited[i])
            {
                q.push(i);
                dis[i] = dis[king] + 1;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    //int V, e;
    cin >> V >> e;
    // Create a graph
    //create an array of vectors
    //here 5 adj vectors are available
    vector<int> adj[V];
    bool visited[V]; //boolean array
    int dis[V];
    initDis(dis);
    initVisited(visited);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }
    printGraph(adj);
    int start;
    cin >> start;
    bfs(adj, start, visited, dis);
    printDis(dis);
}
