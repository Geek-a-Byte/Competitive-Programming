#include <bits/stdc++.h>
using namespace std;

int V, e;
bool *visited;
int *dis;
// Add edge
void addEdge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void printGraph(vector<int> adj[])
{
    cout << endl;
    // Traversing of vectors v to print
    // elements stored in it
    for (int i = 0; i < V; i++)
    {

        cout << "Elements at index "
             << i << ": ";

        // Displaying element at each column,
        // begin() is the starting iterator,
        // end() is the ending iterator
        for (auto it = adj[i].begin();
             it != adj[i].end(); it++)
        {

            // (*it) is used to get the
            // value at iterator is
            // pointing
            cout << *it << ' ';
        }
        cout << endl;
    }
}
void printDis()
{
    for (int i = 0; i < V; i++)
    {
        cout << "distance"
             << " of  " << i << " is " << dis[i] << endl;
    }
}

void initVisited()
{
    for (int i = 0; i < V; i++)
    {
        *(visited + i) = false;
    }
}
void initDis()
{
    for (int i = 0; i < V; i++)
    {
        *(dis + i) = 0;
    }
}

void bfs(vector<int> adj[], int start)
{
    //initMark();
    queue<int> q;
    q.push(start);
    *(visited + start) = true;

    while (!q.empty())
    {
        int king = q.front();
        cout << king << " ";
        q.pop();

        for (auto i = adj[king].begin(); i != adj[king].end(); i++)
        {
            if (!*(visited + *i))
            {
                q.push(*i);
                *(dis + *i) = dis[king] + 1;
                *(visited + *i) = true;
            }
        }
    }
}

int main()
{
    cin >> V >> e;
    // Create a graph
    //create an array of vectors
    //here 5 adj vectors are available
    vector<int> adj[V];
    visited = (bool *)malloc(V * sizeof(bool));
    dis = (int *)malloc(V * sizeof(int));
    // dis = new int[V];
    // visited = new bool[V];
    initDis();
    initVisited();
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }
    printGraph(adj);
    int start;
    cin >> start;
    bfs(adj, start);
    printDis();
    free(dis);
    free(visited);
}
