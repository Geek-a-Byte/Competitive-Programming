#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int nodes, edges;

// vector<vector<int>> array_2d(100, vector<int>(100, 0));
vector<vector<int>> adj;
vector<int> mark;
vector<int> dis;

void initAdj()
{
    for (int i = 0; i < nodes; i++)
    {
        vector<int> row1;
        for (int j = 0; j < nodes; j++)
        {
            row1.push_back(0);
        }
        adj.push_back(row1);
    }
}
void initMark()
{
    for (int i = 0; i < nodes; i++)
    {
        mark.push_back(0);
    }
}
void initDis()
{
    for (int i = 0; i < nodes; i++)
    {
        dis.push_back(0);
    }
}

void printDis()
{
    for (int i = 0; i < nodes; i++)
    {
        cout << "distance"
             << " of  " << i << " is " << dis[i] << endl;
    }
}
void printMark()
{
    for (int i = 0; i < nodes; i++)
    {
        cout << "Mark"
             << " of  " << i << " is " << mark[i] << endl;
    }
}
void printAdj()
{
    for (int j = 0; j < nodes; j++)
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << adj[j][i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    cin >> nodes >> edges;
    adj.resize(nodes * nodes);
    cout << adj.size() << endl;
    initAdj();
    initMark();
    initDis();

    for (int i = 1; i <= edges; i++)
    {
        int x, y;
        cin >> x >> y;
        //adj[x].push_back(y);
    }
    printAdj();
    printMark();
    printDis();
}