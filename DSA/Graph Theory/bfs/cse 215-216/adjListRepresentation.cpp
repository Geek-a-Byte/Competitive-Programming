// Adjascency List representation in C++

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int V, e;
// Add edge
void addEdge(vector<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<int> adj[])
{

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

int main()
{
    //int V, e;
    cin >> V >> e;
    // Create a graph
    //create an array of vectors
    //here 5 adj vectors are available
    vector<int> adj[V];

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(adj, x, y);
    }
    // Add edges
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 1, 2);
    printGraph(adj);
}
